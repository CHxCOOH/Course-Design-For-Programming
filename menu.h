//菜单及UI
#pragma once
#ifndef MENU_H
#define MENU_H

#include "settings.h"

class menu {
public:
	menu();
	void entryMenu() const;					//登录/注册界面
	void entryMenu0() const;				//首次注册页面
	void registerHint() const;				//用户名密码格式提示
	void registerLenInvalid() const;		//用户名密码长度错误
	void registerUserAlreadyExist() const;	//用户名已存在
	void registerSuccess() const;			//注册成功
	void loginHint1() const;				//登录提示（输入用户名）
	void loginHint2() const;				//登录提示（输入密码）
	void loginSuccess() const;				//登录成功
	void loginFailed() const;				//登录失败
	void logoutSuccess() const;				//登出成功
	void displayUsersHint() const;			//显示所有用户提示
	void displayUsersEditHint() const;		//更多对用户操作提示
	void userIndexHint() const;				//输入用户序号提示
	void userIndexError() const;			//用户序号非法
	void editUserHint() const;				//编辑用户提示
	void editUserMenu(bool isadmin) const;	//编辑用户选项
	void editUsernameHint() const;			//编辑用户名提示
	void editPasswordHint() const;			//编辑密码提示
	void editUserSuccess() const;			//编辑用户成功
	void editFailed() const;				//编辑用户失败
	void functionMenu(bool isAdmin) const;	//功能菜单页面
	void addId_cardHint() const;			//添加身份信息提示
	void addId_cardHint2() const;			//添加身份信息提示
	void addId_cardAlreadyExist() const;	//身份证号重复错误
	void addIdSuccess() const;				//添加成功
	void queryIdHint() const;				//查询身份信息提示
	void querySuccess() const;				//查询成功
	void querIdEditHint() const;			//查询后更多操作提示
	void queryId_cardHint() const;			//模糊查询提示
	void queryFuzzySuccess(int n) const;	//模糊查询成功
	void idNotFound() const;				//身份证号不存在
	void sortHint() const;					//排序身份信息提示
	void sortidSuccess() const;				//排序成功
	void markDeathHint() const;				//注销身份信息提示
	void markedSuccess() const;				//注销成功
	void displayId_cardHint() const;		//显示所有信息提示
	void pause() const;						//控制台暂停
	void editId_cardHint() const;			//编辑身份信息提示
	void editId_cardOption() const;			//编辑项目选择
	void editSuccess() const;				//编辑成功
	void editNameHint() const;				//编辑姓名提示
	void editGenderHint() const;			//编辑性别提示
	void editNationHint() const;			//编辑民族提示
	void editAddressHint() const;			//编辑地址提示
	void editBirthHint() const;				//编辑生日提示
	void deleteId_cardHint() const;			//删除身份信息提示
	void deleteSuccess() const;				//删除成功
	void exportSuccess() const;				//导出成功
private:
	void printLogo() const;					//清屏并打印系统LOGO
};

#endif
