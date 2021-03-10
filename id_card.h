#pragma once
#ifndef ID_CARD_H
#define ID_CARD_H

#include "settings.h"

class id_card {
public:
	id_card();
	id_card(string ID);
	id_card(unsigned long long ID);
	id_card(string ID, string Name, string Gender, string Address, string Nation, string Birthdate);
	id_card(string ID, string Name, bool ismale, string Address, string Nation, string Birthdate);
	void editName(string Name);				//修改姓名
	void editGender(string Gender);			//修改性别
	void editAddress(string Address);		//修改地址
	void editNation(string Nation);			//修改民族
	void editBirthdate(string Birthdate);	//修改出生日期
	void updateCard();						//修改办理、截止日期
	void markDeath();						//标记死亡
	unsigned long long getId();				//返回身份证号（无符号长整型）
	const string& getName() const;			//返回姓名（string形式）
	const string& getId() const;			//返回身份证号（string形式）
	const string& getGender() const;		//返回性别（string形式）
	const string& getAddress() const;		//返回地址（string形式）
	const string& getNation() const;		//返回民族（string形式）
	const string& getBirthdate() const;		//返回出生日期（string形式）
	const string& getStartdate() const;		//返回办理日期（string形式）
	const string& getEnddate() const;		//返回截止日期（string形式）
	string getInfo() const;			//返回身份证信息（string形式，Tab分隔）
	bool operator<(const id_card& o) const;	//重载小于号，便于排序
	bool operator>(const id_card& o) const;	//重载大于号
	bool operator==(const id_card& o) const;//重载关系运算符
	bool operator!=(const id_card& o) const;//重载关系运算符
	bool operator<=(const id_card& o) const;//重载关系运算符
	bool operator>=(const id_card& o) const;//重载关系运算符
private:
	string id;					//身份证号（string形式）
	unsigned long long id_int64;//身份证号（长整型）
	string name;				//姓名			
	string gender;				//性别（string，男/女）
	bool isMale;				//性别（bool）
	string address;				//地址
	string nation;				//民族
	string birthdate;			//出生日期
	string startdate;			//办理日期
	string enddate;				//截止日期

	friend ostream& operator<<(ostream& o, const id_card& id) {	//输出身份证信息（csv格式，逗号分隔）
		o << id.id + "," + id.name + "," + id.gender + "," + id.nation + "," + id.birthdate + "," + id.startdate + "," + id.enddate + "," + id.address;
		return o;
	}
friend istream& operator>>(istream& i, id_card& id) {	//读入身份证信息（从csv文件，按行）
	getline(i, id.id, ',');
	getline(i, id.name, ',');
	getline(i, id.gender, ',');
	getline(i, id.nation, ',');
	getline(i, id.birthdate, ',');
	getline(i, id.startdate, ',');
	getline(i, id.enddate, ',');
	getline(i, id.address);
	if ( id.address == "" )
		return i;
	if ( id.id[17] != 'X' && id.id[17] != 'x' )
		id.id_int64 = stoull(id.id);
	else {
		stringstream ss(id.id);
		ss >> id.id_int64;
	}
	id.isMale = id.gender == "男";
	return i;
}
};

#endif