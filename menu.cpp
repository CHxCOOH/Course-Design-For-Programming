#include "menu.h"
Settings S;

menu::menu() {
	system("mode con cols=120 lines=40");
	system("color F0");
}

void menu::entryMenu() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t1. 登录" << endl << endl;
	cout << "\t\t\t\t\t\t\t2. 注册" << endl << endl;
	cout << "\t\t\t\t\t\t\tESC. 退出" << endl << endl;
}

void menu::entryMenu0() const {
	printLogo();
	cout << "\t\t\t\t\t检测到还未有管理员注册，请注册管理员账号。" << endl << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::registerHint() const {
	printLogo();
	cout << "\t\t\t\t\t\t用户名和密码均不多于16字符，" << endl << endl;
	cout << "\t\t\t\t\t\t任意大小写字母、数字均可。" << endl << endl;
	cout << "\t\t\t\t\t请输入用户名（3-16字符）：";
}

void menu::registerLenInvalid() const {
	cout << endl << "\t\t\t\t\t\t请检查是否过长或过短" << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::registerUserAlreadyExist() const {
	cout << endl << "\t\t\t\t\t\t系统存在相同的用户名" << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::registerSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t注册成功！" << endl << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::loginHint1() const {
	printLogo();
	cout << "\t\t\t\t\t请输入用户名（3-16字符）：";
}

void menu::loginHint2() const {
	cout << "\n\n\t\t\t\t\t 请输入密码 （6-16字符）：";
}

void menu::loginSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t登录成功！" << endl << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::loginFailed() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t登录失败！" << endl << endl;
	cout << "\t\t\t\t\t\t请检查用户名或密码是否错误";
	system("pause");
}

void menu::logoutSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t登出成功！" << endl << endl;
	cout << "\t\t\t\t\t\t";
	system("pause");
}

void menu::displayUsersHint() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t用户列表" << endl << endl;
	cout << S.line << endl << endl;
}

void menu::displayUsersEditHint() const {
	cout << S.line << endl;
	cout << "\n\t\t\t\t\t是否编辑用户信息？（Y/N）" << endl;
}

void menu::userIndexHint() const {
	cout << "\n\t\t\t\t\t请输入用户序号： ";
}

void menu::userIndexError() const {
	cout << "\t\t\t\t\t\t用户序号非法！";
	system("pause");
}

void menu::editUserHint() const {
	printLogo();
	cout << "\t\t请输入目标用户序号（自0开始，如不清楚可返回上一级，显示所有用户信息）" << endl;
	cout << "\t\t\t\t\t用户序号：";
}

void menu::editUserMenu(bool isadmin) const {
	printLogo();
	cout << "\n\n"
		 << "\t\t\t\t\t\t1. 更改用户名\n\n"
		 << "\t\t\t\t\t\t2. 更改密码\n\n"
		 << (isadmin?"\t\t\t\t\t\t3. 设为管理员\n\n":"")
		 << "\t\t\t\t\t\tESC. 返回上一级" << endl;
}

void menu::editUsernameHint() const {
	cout << S.line << endl;
	cout << "\n\t\t\t\t\t用户名的长度为3~16个英文或数字字符" << endl << endl;
	cout << "\t\t\t\t\t新用户名：";
}

void menu::editPasswordHint() const {
	cout << S.line << endl;
	cout << "\n\t\t\t\t\t密码的长度为6~16个英文或数字字符" << endl << endl;
	cout << "\t\t\t\t\t   新密码：";
}

void menu::editUserSuccess() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t\t\t编辑成功！" << endl;
	system("pause");
}

void menu::editFailed() const {
	printLogo();
	cout << "\n\t\t\t\t\t\t编辑失败！" << endl << endl;
	cout << "\t\t\t\t\t请联系系统管理员以获得帮助。" << endl;
	system("pause");
}

void menu::functionMenu(bool isAdmin) const {
	printLogo();
	cout << "\n";
	if ( isAdmin ) {
		cout<< "\t\t\t\t\t\t1. 添加身份信息\n\n"
			<< "\t\t\t\t\t\t2. 查找身份信息（按身份证号）\n\n"
			<< "\t\t\t\t\t\t3. 编辑身份信息（按身份证号）\n\n"
			<< "\t\t\t\t\t\t4. 删除身份信息（按身份证号）\n\n"
			<< "\t\t\t\t\t\t5. 注销身份信息（死亡，按身份证号）\n\n"
			<< "\t\t\t\t\t\t6. 排序所有信息\n\n"
			<< "\t\t\t\t\t\t7. 显示所有身份信息\n\n"
			<< "\t\t\t\t\t\t8. 显示所有用户信息\n\n"
			<< "\t\t\t\t\t\t9. 保存到文件\n\n"
			<< "\t\t\t\t\t\t0. 模糊查找身份信息\n\n"
			<< "\t\t\t\t\t\tESC.退出登录" << endl;
	} else {
		cout<< "\t\t\t\t\t\t1. 查找身份信息（按身份证号）\n\n"
			<< "\t\t\t\t\t\t2. 更改当前用户信息 \n\n"
			<< "\t\t\t\t\t\tESC.退出登录" << endl;
	}
}

void menu::addId_cardHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t请输入要添加的身份证号（回车结束）：";
}

void menu::addId_cardHint2() const {
	cout << "\n\t\t\t\t请按提示输入，各项空格分隔，日期示例: 2020-06-30" << endl;
	cout << "\n\t姓名\t\t性别\t\t民族\t\t出生日期\t\t地址\n\n\t";
}

void menu::addId_cardAlreadyExist() const {
	printLogo();
	cout << "\t\t\t\t\t\t错误！该身份证号已存在！" << endl;
	system("pause");
}

void menu::addIdSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t添加身份信息成功！" << endl;
	system("pause");
}

void menu::queryIdHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t请输入要查询的身份证号（回车结束）：";
}

void menu::querySuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t查询身份信息成功！" << endl << endl;
	cout << S.line << endl;
	cout << left << setw(20) << "身份证号" << setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "民族" << setw(12) << "出生日期" << setw(12) << "办理日期" << setw(12) << "截止日期" << setw(42) << "地址" << endl << endl;
}

void menu::querIdEditHint() const {
	cout<< "\t\t\t\t\t\t是否进行更多操作？\n\n"
		<< "\t\t\t\t\t\t1. 编辑身份信息\n\n"
		<< "\t\t\t\t\t\t2. 删除身份信息\n\n"
		<< "\t\t\t\t\t\t3. 注销身份信息（死亡）\n\n"
		<< "\t\t\t\t\t\tESC. 返回上一级" << endl;
}

void menu::queryId_cardHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t请输入任意要查询的身份信息（回车结束）：";
}

void menu::queryFuzzySuccess(int n) const {
	cout << "\t\t\t\t\t模糊查询成功！共查到" << n << "条身份信息。" << endl;
	cout << S.line << endl;
	system("pause");
}

void menu::idNotFound() const {
	printLogo();
	cout << "\t\t\t\t\t错误！未找到符合条件的身份信息！";
	system("pause");
}

void menu::sortHint() const {
	printLogo();
	cout<< "\n\n\t\t\t\t\t\t请选择排序方式\n\n"
		<< "\t\t\t\t\t\t1. 按身份证号升序\n\n"
		<< "\t\t\t\t\t\t2. 按身份证号降序\n\n"
		<< "\t\t\t\t\t\t3. 按姓名升序\n\n"
		<< "\t\t\t\t\t\tESC. 返回上一级" << endl;
}

void menu::sortidSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t\t排序成功！";
	system("pause");
}

void menu::markDeathHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t请输入要注销的身份证号（回车结束）：";
}

void menu::markedSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t注销身份信息成功！";
	system("pause");
}

void menu::editId_cardHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t请输入要编辑的身份证号（回车结束）：";
}

void menu::editId_cardOption() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t\t请选择编辑项目\n\n"
		<< "\t\t\t\t\t\t1. 姓名\n\n"
		<< "\t\t\t\t\t\t2. 性别\n\n"
		<< "\t\t\t\t\t\t3. 民族\n\n"
		<< "\t\t\t\t\t\t4. 地址\n\n"
		<< "\t\t\t\t\t\t5. 出生日期\n\n"
		<< "\t\t\t\t\t\t6. 更换新卡（续期）\n\n"
		<< "\t\t\t\t\t\tESC. 返回上一级" << endl;
}

void menu::editSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t编辑身份信息成功！";
	system("pause");
}

void menu::editNameHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t请输入姓名（回车结束）：";
}

void menu::editGenderHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t请输入性别（回车结束）：";
}

void menu::editNationHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t请输入民族（回车结束）：";
}

void menu::editAddressHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t请输入地址（回车结束）：";
}

void menu::editBirthHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t\t请输入出生日期（回车结束）：";
}

void menu::deleteId_cardHint() const {
	printLogo();
	cout << "\n\n\t\t\t\t请输入要删除的身份证号（回车结束）：";
}

void menu::deleteSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t删除身份信息成功！";
	system("pause");
}

void menu::displayId_cardHint() const {
	printLogo();
	cout << "\n";
	cout << left << setw(20) << " 身份证号" << setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "民族" << setw(12) << "出生日期" << setw(12) << "办理日期" << setw(12) << "截止日期" << setw(42) << "地址" << endl << endl;
}

void menu::pause() const {
	system("pause");
}

void menu::exportSuccess() const {
	printLogo();
	cout << "\t\t\t\t\t\t导出身份信息成功！";
	system("pause");
}

void menu::printLogo() const {
	system("cls");
	cout << "\n\n";
	cout << "\t\t\t\t   ╭═══════════════════════════════════○●○●═══╮" << endl;
	cout << "\t\t\t\t  │            欢迎进入身份信息管理系统            │" << endl;
	cout << "\t\t\t\t  ╰ ═══○●○●═══════════════════════════════════ ╯" << endl << endl;
	cout << S.line << endl << endl;
}
