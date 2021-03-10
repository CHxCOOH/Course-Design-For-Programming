#include "system.h"

Settings s;
menu m;

bool compareName(const id_card& l, const id_card& r) {
	return l.getName() < r.getName();
}

System::System() : activeUser(-1) {
	ifstream f_users;
	f_users.open(s.userfile);
	if ( !f_users ) {				//如果打开失败（第一次登录）
		activeUser = -2;
		initFile();
		return;
	}
	readFromFile();
	f_users.close();
}

void System::sysEntry() {
	if ( activeUser == -2 ) {	//首次登录强制注册
		m.entryMenu0();
		Register();
		activeUser = 0;
		sysFuncs();
	}
	while ( true ) {
		m.entryMenu();
		switch ( _getch()) {
			case '1':
				login();
				break;
			case '2':
				Register();
				break;
			case 27:
				exit(EXIT_SUCCESS);
			default:
				break;
		}
	}
}

void System::sysFuncs() {
	while ( true ) {
		bool isadmin = users[activeUser].isadmin();
		m.functionMenu(isadmin);
		if ( isadmin ) {
			switch ( _getch() ) {
				case 27:
					logout();
					return;
				case '1':
					addId_cardInfo();
					break;
				case '2':
					queryId();
					break;
				case '3':
					editId_card();
					break;
				case '4':
					deleteId_card();
					break;
				case '5':
					markForDeath();
					break;
				case '6':
					sortId_card();
					break;
				case '7':
					displayId_cards();
					break;
				case '8':
					displayUsers();
					break;
				case '9':
					exportToFile();
					break;
				case '0':
					queryId_cardFuzzy();
					break;
				default:
					break;
			}
		} else {
			switch ( _getch() ) {
				case 27:
					return;
					break;
				case '1':
					queryId();
					break;
				case '2':
					editUser();
					break;
				default:
					break;
			}
		}
	}
}

void System::initFile() {
	ofstream f_users(s.userfile), f_id(s.datafile), f_death(s.deathfile);
	f_users << s.userFileHead;
	f_id << s.dataFileHead;
	f_death << s.dataFileHead;
	f_users.close();
	f_id.close();
	f_death.close();
}

void System::readFromFile() {
	char tmp[128];
	ifstream f_users(s.userfile), f_id(s.datafile);
	//读入用户信息
	f_users.getline(tmp, 128);
	user tu;
	while ( f_users >> tu ) {
		users.push(tu);
	}
	f_users.close();
	//读入身份信息
	f_id.getline(tmp, 128);
	id_card ti;
	while ( f_id >> ti ) {
		id_cards.push_back(ti);
	}
	f_id.close();
}

void System::Register() {
	string name, pass;
	m.registerHint();
	while ( cin >> name ) {
		if ( name.size() < 3 && name.size() > 16 ) {
			m.registerLenInvalid();
			m.registerHint();
			cin.clear();
			continue;
		}
		if ( !users.isUnique(user(name, pass, false)) ) {
			m.registerUserAlreadyExist();
			m.registerHint();
			continue;
		}
		break;
	}
	cout << "\n\t\t\t\t\t请输入密码（6-16字符）：";
	while ( cin >> pass ) {
		if ( pass.size() < 6 && pass.size() > 16 ) {
			m.registerLenInvalid();
			cin.clear();
			continue;
		}
		break;
	}
	m.registerSuccess();
	user u(name, pass, activeUser==-2?true:false);	//如果是第一个用户，自动成为管理员，否则需要借助其他管理员提权
	users.push(u);
	exportUsersToFile();
}

void System::login() {
	string username, password;
	while ( true )	{
		m.loginHint1();
		cin.clear();
		cin >> username;
		m.loginHint2();
		cin.clear();
		cin >> password;
		int len = users.len();
		for ( int i = 0; i < len; i++ ) {
			if ( users[i].login(username, password) ) {
				activeUser = i;
				m.loginSuccess();
				sysFuncs();
				return;
			}
		}
		m.loginFailed();
	}
}

void System::logout() {
	activeUser = -1;
	exportUsersToFile();
	exportId_cardToFile();
	m.logoutSuccess();
}

bool System::deleteUser(int index) {
	if ( index != activeUser && isIndexLegel(index) && users[activeUser].isadmin() ) {	//下标合法，要删除用户并非当前用户，且当前用户是管理员
		users.Delete(index);
		exportUsersToFile();
		return true;
	}
	return false;
}

bool System::updateUserPriv(int index) {
	if ( isIndexLegel(index) && users[activeUser].isadmin() ) {	//下标合法，且当前用户是管理员
		users[index].updagePrivs();
		exportUsersToFile();
		return true;
	}
	return false;
}

void System::editUser() {
	if ( users[activeUser].isadmin() ) {
		m.editUserHint();
		int index;
		cin.clear();
		cin >> index;
		if ( !isIndexLegel(index) ) {
			m.userIndexError();
			return;
		}
		editUser(index);
	} else {
		editUser(activeUser);
	}
}

void System::editUser(int index) {
	while ( true ) {
		bool isadmin = users[activeUser].isadmin();
		m.editUserMenu(isadmin);
		string input;
		bool success = false;
		switch ( _getch() ) {
			case 27:
				return;
				break;
			case '1':
				m.editUsernameHint();
				cin.clear();
				cin >> input;
				success = updateUsername(index, input);
				break;
			case '2':
				m.editPasswordHint();
				cin.clear();
				cin >> input;
				success = updatePassword(index, input);
				break;
			case '3':
				if ( isadmin )
					success = updateUserPriv(index);
				break;
			default:
				continue;
				break;
		}
		if ( success ) {
			m.editUserSuccess();
		} else {
			m.editFailed();
		}
	}
}

bool System::updateUsername(int index, string newName) {
	if ( isIndexLegel(index) && (users[activeUser].isadmin() || index == activeUser) ) {//下标合法，且当前用户是管理员，或者更改自己的用户名
		if ( !users.isUnique(user(newName, "", false)) ) {
			return false;
		}
		users[index].changeUsername(newName);
		exportUsersToFile();
		return true;
	}
	return false;
}

bool System::updatePassword(int index, string newPass) {
	if ( isIndexLegel(index) && (users[activeUser].isadmin() || index == activeUser) ) {//下标合法，且当前用户是管理员，或者更改自己的用户名
		users[index].changePassword(newPass);
		exportUsersToFile();
		return true;
	}
	return false;
}

void System::displayUsers() {
	while ( true ) {
		m.displayUsersHint();
		int len = users.len();
		cout << setw(8) << "序号" << setw(32) << "用户名" << setw(40) << "密码" << setw(20) << "类别" << endl << endl;
		for ( int i = 0; i < len; i++ ) {
			cout << setw(8) << i << setw(32) << users[i].getUsername() << setw(40) << users[i].getPassword() << setw(20) << (users[i].isadmin() ? "管理员" : "用户") << endl << endl;
		}
		m.displayUsersEditHint();
		int key = _getch();
		if ( key == 27 || key == 'n' || key == 'N' ) {
			return;
		} else {
			m.userIndexHint();
			int index;
			cin.clear();
			cin >> index;
			if ( !isIndexLegel(index) ) {
				m.userIndexError();
				continue;
			}
			editUser(index);
		}
	}
}

void System::displayId_cards() const {
	m.displayId_cardHint();
	for ( auto it = id_cards.begin(); it != id_cards.end(); it++ ) {
		cout << it->getInfo() << endl << endl;
	}
	cout << "共" << id_cards.size() << "条身份信息。" << endl << endl;
	m.pause();
}

void System::addId_cardInfo() {
	string id;
	m.addId_cardHint();
	cin.clear();
	cin >> id;
	unsigned long long id_int64;
	if ( id[17] != 'X' && id[17] != 'x' )
		id_int64 = stoull(id);
	else {
		stringstream ss(id);
		ss >> id_int64;
	}
	if ( findId(id_int64) != id_cards.end() ) {
		m.addId_cardAlreadyExist();
	} else {
		m.addId_cardHint2();
		string name, gender, nation, address, birthdate;
		cin.clear();
		cin >> name >> gender >> nation >> birthdate >> address;
		id_card i(id, name, gender, address, nation, birthdate);
		id_cards.push_back(i);
		exportId_cardToFile();
		m.addIdSuccess();
	}
}

void System::deleteId_card() {
	while ( true ) {
		string id;
		unsigned long long id_int64;
		m.deleteId_cardHint();
		cin.clear();
		cin >> id;
		if ( id[17] != 'X' && id[17] != 'x' )
			id_int64 = stoull(id);
		else {
			stringstream ss(id);
			ss >> id_int64;
		}
		auto it = findId(id_int64);
		if ( it == id_cards.end() ) {	//没找到
			m.idNotFound();
			return;
		}
		id_cards.erase(it);
		exportId_cardToFile();
		m.deleteSuccess();
		return;
	}
}

void System::deleteId_card(vector<id_card>::iterator it) {
	id_cards.erase(it);
	exportId_cardToFile();
}

void System::editId_card() {
	while ( true ) {
		string id;
		unsigned long long id_ull;
		m.editId_cardHint();
		cin.clear();
		cin >> id;
		if ( id[17] != 'X' && id[17] != 'x' )
			id_ull = stoull(id);
		else {
			stringstream ss(id);
			ss >> id_ull;
		}
		auto it = findId(id_ull);
		if ( it == id_cards.end() ) {
			m.idNotFound();
			return;
		}
		editId_card(it);
		return;
	}
}

void System::editId_card(vector<id_card>::iterator it) {
	while ( true ) {
		m.editId_cardOption();
		switch ( _getch() ) {
			case 27:
				return;
				break;
			case '1':
				updateName(it);
				break;
			case '2':
				updateGender(it);
				break;
			case '3':
				updateNation(it);
				break;
			case '4':
				updateAddress(it);
				break;
			case '5':
				updateBirthdate(it);
				break;
			case '6':
				updateCard(it);
				break;
			default:
				break;
		}
	}
}

void System::updateCard(vector<id_card>::iterator it) {
	it->updateCard();
	exportId_cardToFile();
	m.editSuccess();
}

void System::updateName(vector<id_card>::iterator it) {
	m.editNameHint();
	string name;
	cin.clear();
	cin >> name;
	it->editName(name);
	exportId_cardToFile();
	m.editSuccess();
}

void System::updateGender(vector<id_card>::iterator it) {
	m.editGenderHint();
	string gen;
	cin.clear();
	cin >> gen;
	it->editGender(gen);
	exportId_cardToFile();
	m.editSuccess();
}

void System::updateAddress(vector<id_card>::iterator it) {
	m.editAddressHint();
	string address;
	cin.clear();
	cin >> address;
	it->editAddress(address);
	exportId_cardToFile();
	m.editSuccess();
}

void System::updateNation(vector<id_card>::iterator it) {
	m.editNationHint();
	string nation;
	cin.clear();
	cin >> nation;
	it->editNation(nation);
	exportId_cardToFile();
	m.editSuccess();
}

void System::updateBirthdate(vector<id_card>::iterator it) {
	m.editBirthHint();
	string birth;
	cin.clear();
	cin >> birth;
	it->editBirthdate(birth);
	exportId_cardToFile();
	m.editSuccess();
}

void System::queryId() {
	string id;
	unsigned long long id_ull;
	m.queryIdHint();
	cin.clear();
	cin >> id;
	if ( id[17] != 'X' && id[17] != 'x' )
		id_ull = stoull(id);
	else {
		stringstream ss(id);
		ss >> id_ull;
	}
	auto it = findId(id_ull);
	if ( it == id_cards.end() ) {
		m.idNotFound();
	} else {
		m.querySuccess();
		cout << it->getInfo() << endl << endl;
		if ( !users[activeUser].isadmin() ) {
			m.pause();
			return;
		}
		m.querIdEditHint();
		switch ( _getch() ) {
			case 27:
				return;
				break;
			case '1':
				editId_card(it);
				break;
			case '2':
				deleteId_card(it);
				break;
			case '3':
				markForDeath(it);
			default:
				break;
		}
	}
}

void System::queryId_cardFuzzy() const {
	m.queryId_cardHint();
	auto it = id_cards.begin();
	int result = 0;
	string str;
	cin.clear();
	cin >> str;
	for ( ; it != id_cards.end(); it++ ) {
		if ( strIdcard(it, str) ) {
			if ( result == 0 ) {
				cout << endl << left << setw(20) << " 身份证号" << setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "民族" << setw(12) << "出生日期" << setw(12) << "办理日期" << setw(12) << "截止日期" << setw(42) << "地址" << endl << endl;
			}
			result++;
			cout << it->getInfo() << endl << endl;
		}
	}
	if ( result ) {
		m.queryFuzzySuccess(result);
	} else {
		m.idNotFound();
	}
	return;
}

void System::sortId_card() {
	while ( true ) {
		m.sortHint();
		switch ( _getch() ) {
			case 27:
				return;
				break;
			case '1':
				sortById();
				break;
			case '2':
				sortByIdDesc();
				break;
			case '3':
				sortbyName();
				break;
			default:
				continue;
		}
		exportId_cardToFile();
		m.sortidSuccess();
		return;
	}
}

void System::sortById() {
	sort(id_cards.begin(), id_cards.end());
}

void System::sortByIdDesc() {
	sort(id_cards.begin(), id_cards.end(), greater<id_card>());
}

void System::sortbyName() {
	sort(id_cards.begin(), id_cards.end(), compareName);
}

void System::markForDeath() {
	string id;
	unsigned long long id_int64;
	m.markDeathHint();
	cin.clear();
	cin >> id;
	if ( id[17] != 'X' && id[17] != 'x' )
		id_int64 = stoull(id);
	else {
		stringstream ss(id);
		ss >> id_int64;
	}
	auto it = findId(id_int64);
	if ( it == id_cards.end() ) {
		m.idNotFound();
		return;
	}
	markForDeath(it);
	exportId_cardToFile();
	m.markedSuccess();
	return;
}

void System::markForDeath(vector<id_card>::iterator it) {
	it->markDeath();
	auto tmp = *it;
	id_cards.erase(it);
	writeToDeath(tmp);
}

void System::exportToFile() const {
	exportId_cardToFile();
	exportUsersToFile();
	m.exportSuccess();
}

void System::exportId_cardToFile() const {
	ofstream f_id(s.datafile);
	f_id << s.dataFileHead;
	for ( auto it = id_cards.begin(); it != id_cards.end(); it++ ) {
		f_id << "\n" << *it ;
	}
	f_id.close();
}

void System::exportUsersToFile() const {
	ofstream f_users(s.userfile);
	f_users << s.userFileHead;
	int len = users.len();
	for ( int i = 0; i < len; i++ ) {
		f_users << "\n" << users[i];
	}
	f_users.close();
}

void System::writeToDeath(const id_card& i) {
	ofstream f_death(s.deathfile, ios::app);
	f_death << endl << i;
	f_death.close();
}

bool System::isIndexLegel(int index) const {
	if ( index >= 0 && index < users.len() && activeUser != -1 )
		return true;
	return false;
}

bool System::strIdcard(vector<id_card>::const_iterator it, string str) const {
	if ( it->getInfo().find(str) != string::npos ) {	//子串存在
		return true;
	}
	return false;
}

vector<id_card>::iterator System::findId(unsigned long long id_ull) {
	return find(id_cards.begin(), id_cards.end(), id_card(id_ull));
}

vector<id_card>::const_iterator System::findId(unsigned long long id_ull) const {
	return find(id_cards.begin(), id_cards.end(), id_card(id_ull));
}
