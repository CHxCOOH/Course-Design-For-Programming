//非UI类的操作函数
#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H
#include "user.h"
#include "menu.h"
#include "linkedList.h"
#include "id_card.h"

class System {
public:
	System();
	void sysEntry();				//系统入口函数
private:
	int activeUser;					//当前的管理员用户
	linkedList<user> users;			//所有用户列表
	vector<id_card> id_cards;		//所有身份证信息
private:
	void sysFuncs();				//系统主函数					
	void addId_cardInfo();			//添加个人信息
	void deleteId_card();			//删除个人信息（按身份证号）
	void editId_card();				//编辑个人信息（按身份证号）
	void markForDeath();			//标记死亡（按身份证号）
	void queryId();					//查询个人信息（按身份证号）
	void queryId_cardFuzzy() const;	//查询个人信息（模糊查找）
	void displayUsers();			//显示所有用户
	void sortId_card();				//排序
	void exportToFile() const;		//导出所有信息
private:
	void initFile();								//首次打开时初始化文件
	void readFromFile();							//从文件读取数据
	void Register();								//注册
	void login();									//登录
	void logout();									//登出
	bool deleteUser(int index);						//删除指定用户
	bool updateUserPriv(int index);					//提升普通用户权限
	void editUser();								//更改用户信息
	void editUser(int index);						//更改用户信息（按下标）
	bool updateUsername(int index, string newName);	//更改用户名
	bool updatePassword(int index, string newPass);	//更改密码
	void displayId_cards() const;					//显示所有身份信息
	void deleteId_card(vector<id_card>::iterator it);						//删除指定信息
	void editId_card(vector<id_card>::iterator it);							//编辑指定信息
	void updateCard(vector<id_card>::iterator it);							//更新卡片
	void updateName(vector<id_card>::iterator it);							//更改姓名
	void updateGender(vector<id_card>::iterator it);						//更改性别
	void updateAddress(vector<id_card>::iterator it);						//更改地址
	void updateNation(vector<id_card>::iterator it);						//更改民族
	void updateBirthdate(vector<id_card>::iterator it);						//更改出生日期
	void sortById();														//按身份证号升序
	void sortByIdDesc();													//按身份证号降序
	void sortbyName();														//按姓名排序
	void markForDeath(vector<id_card>::iterator it);						//标记指定身份死亡
	void exportId_cardToFile() const;										//导出信息到文件（可打印）
	void exportUsersToFile() const;											//导出用户到文件
	void writeToDeath(const id_card& i);									//写入死亡的身份信息到文件
	bool isIndexLegel(int index) const;										//检查用户下标是否合法
	bool strIdcard(vector<id_card>::const_iterator it, string str) const;	//模糊查找str是否出现在指定身份信息中
	vector<id_card>::iterator findId(unsigned long long id_ull);			//检查身份证号是否存在
	vector<id_card>::const_iterator findId(unsigned long long id_ull) const;//检查身份证号是否存在
};

#endif
