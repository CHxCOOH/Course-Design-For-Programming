#include "menu.h"
Settings S;

menu::menu() {
	system("mode con cols=120 lines=40");
	system("color F0");
}

void menu::entryMenu() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t1. ��¼" << endl << endl;
	cout << "\t\t\t\t\t\t\t2. ע��" << endl << endl;
	cout << "\t\t\t\t\t\t\tESC. �˳�" << endl << endl;
}

void menu::entryMenu0() const {
	printLogo();
	cout << "\t\t\t\t\t��⵽��δ�й���Աע�ᣬ��ע�����Ա�˺š�" << endl << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::registerHint() const {
	printLogo();
	cout << "\t\t\t\t\t\t�û����������������16�ַ���" << endl << endl;
	cout << "\t\t\t\t\t\t�����Сд��ĸ�����־��ɡ�" << endl << endl;
	cout << "\t\t\t\t\t�������û�����3-16�ַ�����";
}

void menu::registerLenInvalid() const {
	cout << endl << "\t\t\t\t\t\t�����Ƿ���������" << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::registerUserAlreadyExist() const {
	cout << endl << "\t\t\t\t\t\tϵͳ������ͬ���û���" << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::registerSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t\tע��ɹ���" << endl << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::loginHint1() const {
	printLogo();
	cout << "\t\t\t\t\t�������û�����3-16�ַ�����";
}

void menu::loginHint2() const {
	cout << "\n\n\t\t\t\t\t ���������� ��6-16�ַ�����";
}

void menu::loginSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t��¼�ɹ���" << endl << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::loginFailed() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t��¼ʧ�ܣ�" << endl << endl;
	cout << "\t\t\t\t\t\t�����û����������Ƿ����";
	system("pause");
}

void menu::logoutSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t�ǳ��ɹ���" << endl << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::displayUsersHint() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t�û��б�" << endl << endl;
	cout << S.line << endl << endl;
}

void menu::displayUsersEditHint() const {
	cout << S.line << endl;
	cout << "\n\t\t\t\t\t�Ƿ�༭�û���Ϣ����Y/N��" << endl;
}

void menu::userIndexHint() const {
	cout << "\n\t\t\t\t\t�������û���ţ� ";
}

void menu::userIndexError() const {
	cout << "\t\t\t\t\t\t�û���ŷǷ���";
	system("pause");
}

void menu::editUserHint() const {
	printLogo();
	cout << "\t\t������Ŀ���û���ţ���0��ʼ���粻����ɷ�����һ������ʾ�����û���Ϣ��" << endl;
	cout << "\t\t\t\t\t�û���ţ�";
}

void menu::editUserMenu(bool isadmin) const {
	printLogo();
	cout << "\n\n"
		 << "\t\t\t\t\t\t1. �����û���\n\n"
		 << "\t\t\t\t\t\t2. ��������\n\n"
		 << (isadmin?"\t\t\t\t\t\t3. ��Ϊ����Ա\n\n":"")
		 << "\t\t\t\t\t\tESC. ������һ��" << endl;
}

void menu::editUsernameHint() const {
	cout << S.line << endl;
	cout << "\n\t\t\t\t\t�û����ĳ���Ϊ3~16��Ӣ�Ļ������ַ�" << endl << endl;
	cout << "\t\t\t\t\t���û�����";
}

void menu::editPasswordHint() const {
	cout << S.line << endl;
	cout << "\n\t\t\t\t\t����ĳ���Ϊ6~16��Ӣ�Ļ������ַ�" << endl << endl;
	cout << "\t\t\t\t\t   �����룺";
}

void menu::editUserSuccess() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t\t\t�༭�ɹ���" << endl;
	system("pause");
}

void menu::editFailed() const {
	printLogo();
	cout << "\n\t\t\t\t\t\t�༭ʧ�ܣ�" << endl << endl;
	cout << "\t\t\t\t\t����ϵϵͳ����Ա�Ի�ð�����" << endl;
	system("pause");
}

void menu::functionMenu(bool isAdmin) const {
	printLogo();
	cout << "\n";
	if ( isAdmin ) {
		cout<< "\t\t\t\t\t\t1. ��������Ϣ\n\n"
			<< "\t\t\t\t\t\t2. ���������Ϣ�������֤�ţ�\n\n"
			<< "\t\t\t\t\t\t3. �༭�����Ϣ�������֤�ţ�\n\n"
			<< "\t\t\t\t\t\t4. ɾ�������Ϣ�������֤�ţ�\n\n"
			<< "\t\t\t\t\t\t5. ע�������Ϣ�������������֤�ţ�\n\n"
			<< "\t\t\t\t\t\t6. ����������Ϣ\n\n"
			<< "\t\t\t\t\t\t7. ��ʾ���������Ϣ\n\n"
			<< "\t\t\t\t\t\t8. ��ʾ�����û���Ϣ\n\n"
			<< "\t\t\t\t\t\t9. ���浽�ļ�\n\n"
			<< "\t\t\t\t\t\t0. ģ�����������Ϣ\n\n"
			<< "\t\t\t\t\t\tESC.�˳���¼" << endl;
	} else {
		cout<< "\t\t\t\t\t\t1. ���������Ϣ�������֤�ţ�\n\n"
			<< "\t\t\t\t\t\t2. ���ĵ�ǰ�û���Ϣ \n\n"
			<< "\t\t\t\t\t\tESC.�˳���¼" << endl;
	}
}

void menu::addId_cardHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t������Ҫ��ӵ����֤�ţ��س���������";
}

void menu::addId_cardHint2() const {
	cout << "\n\t\t\t\t�밴��ʾ���룬����ո�ָ�������ʾ��: 2020-06-30" << endl;
	cout << "\n\t����\t\t�Ա�\t\t����\t\t��������\t\t��ַ\n\n\t";
}

void menu::addId_cardAlreadyExist() const {
	printLogo();
	cout << "\t\t\t\t\t\t���󣡸����֤���Ѵ��ڣ�" << endl;
	system("pause");
}

void menu::addIdSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t��������Ϣ�ɹ���" << endl;
	system("pause");
}

void menu::queryIdHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t������Ҫ��ѯ�����֤�ţ��س���������";
}

void menu::querySuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t��ѯ�����Ϣ�ɹ���" << endl << endl;
	cout << S.line << endl;
	cout << left << setw(20) << "���֤��" << setw(8) << "����" << setw(6) << "�Ա�" << setw(6) << "����" << setw(12) << "��������" << setw(12) << "��������" << setw(12) << "��ֹ����" << setw(42) << "��ַ" << endl << endl;
}

void menu::querIdEditHint() const {
	cout<< "\t\t\t\t\t\t�Ƿ���и��������\n\n"
		<< "\t\t\t\t\t\t1. �༭�����Ϣ\n\n"
		<< "\t\t\t\t\t\t2. ɾ�������Ϣ\n\n"
		<< "\t\t\t\t\t\t3. ע�������Ϣ��������\n\n"
		<< "\t\t\t\t\t\tESC. ������һ��" << endl;
}

void menu::queryId_cardHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t����������Ҫ��ѯ�������Ϣ���س���������";
}

void menu::queryFuzzySuccess(int n) const {
	cout << "\t\t\t\t\tģ����ѯ�ɹ������鵽" << n << "�������Ϣ��" << endl;
	cout << S.line << endl;
	system("pause");
}

void menu::idNotFound() const {
	printLogo();
	cout << "\t\t\t\t\t����δ�ҵ����������������Ϣ��";
	system("pause");
}

void menu::sortHint() const {
	printLogo();
	cout<< "\n\n\t\t\t\t\t\t��ѡ������ʽ\n\n"
		<< "\t\t\t\t\t\t1. �����֤������\n\n"
		<< "\t\t\t\t\t\t2. �����֤�Ž���\n\n"
		<< "\t\t\t\t\t\t3. ����������\n\n"
		<< "\t\t\t\t\t\tESC. ������һ��" << endl;
}

void menu::sortidSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t����ɹ���";
	system("pause");
}

void menu::markDeathHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t������Ҫע�������֤�ţ��س���������";
}

void menu::markedSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\tע�������Ϣ�ɹ���";
	system("pause");
}

void menu::editId_cardHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t������Ҫ�༭�����֤�ţ��س���������";
}

void menu::editId_cardOption() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t\t��ѡ��༭��Ŀ\n\n"
		<< "\t\t\t\t\t\t1. ����\n\n"
		<< "\t\t\t\t\t\t2. �Ա�\n\n"
		<< "\t\t\t\t\t\t3. ����\n\n"
		<< "\t\t\t\t\t\t4. ��ַ\n\n"
		<< "\t\t\t\t\t\t5. ��������\n\n"
		<< "\t\t\t\t\t\t6. �����¿������ڣ�\n\n"
		<< "\t\t\t\t\t\tESC. ������һ��" << endl;
}

void menu::editSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t�༭�����Ϣ�ɹ���";
	system("pause");
}

void menu::editNameHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t�������������س���������";
}

void menu::editGenderHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t�������Ա𣨻س���������";
}

void menu::editNationHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t���������壨�س���������";
}

void menu::editAddressHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t�������ַ���س���������";
}

void menu::editBirthHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t������������ڣ��س���������";
}

void menu::deleteId_cardHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t������Ҫɾ�������֤�ţ��س���������";
}

void menu::deleteSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\tɾ�������Ϣ�ɹ���";
	system("pause");
}

void menu::displayId_cardHint() const {
	printLogo();
	cout << "\n";
	cout << left << setw(20) << " ���֤��" << setw(8) << "����" << setw(6) << "�Ա�" << setw(6) << "����" << setw(12) << "��������" << setw(12) << "��������" << setw(12) << "��ֹ����" << setw(42) << "��ַ" << endl << endl;
}

void menu::pause() const {
	system("pause");
}

void menu::exportSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t���������Ϣ�ɹ���";
	system("pause");
}

void menu::printLogo() const {
	system("cls");
	cout << "\n\n";
	cout << "\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�����T�T�T�r" << endl;
	cout << "\t\t\t\t  ��            ��ӭ���������Ϣ����ϵͳ            ��" << endl;
	cout << "\t\t\t\t  �t �T�T�T�����T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �s" << endl << endl;
	cout << S.line << endl << endl;
}
