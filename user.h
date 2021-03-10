#pragma once
#ifndef USER_H
#define USER_H
#include "settings.h"

class user {
public:
	user();
	user(string initName, string initPass, bool isadmin);	//构造函数
	bool login(string usernm, string passwd) const;			//登录
	void changeUsername(string newUsername);				//更改用户名
	void changePassword(string newPassword);				//更改密码
	const string& getUsername() const;						//返回用户名
	const string& getPassword() const;						//返回密码
	void updagePrivs();										//提升普通用户权限
	bool isadmin() const;									//是否是管理员（bool）
	string getInfoCsv() const;								//返回注册信息（string形式）
	bool operator==(const user&) const;						//是否用户名相同（注册时调用）
private:
	string username;	//用户名
	string password;	//密码
	bool isAdmin;		//是否是管理员
public:
	friend istream& operator>>(istream& i, user& u) {		//重载流提取运算符（右移运算符）
		string tmp;
		getline(i, u.username, ',');
		getline(i, u.password, ',');
		getline(i, tmp);
		u.isAdmin = (tmp=="管理员");
		return i;
	}
	friend ostream& operator<<(ostream& o, const user& u) {	//重载流插入运算符（左移运算符）
		o << (u.username + "," + u.password + "," + (u.isAdmin ? "管理员" : "用户"));
		return o;
	}
};

#endif
