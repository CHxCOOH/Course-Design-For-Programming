#pragma once
#ifndef USER_H
#define USER_H
#include "settings.h"

class user {
public:
	user();
	user(string initName, string initPass, bool isadmin);	//���캯��
	bool login(string usernm, string passwd) const;			//��¼
	void changeUsername(string newUsername);				//�����û���
	void changePassword(string newPassword);				//��������
	const string& getUsername() const;						//�����û���
	const string& getPassword() const;						//��������
	void updagePrivs();										//������ͨ�û�Ȩ��
	bool isadmin() const;									//�Ƿ��ǹ���Ա��bool��
	string getInfoCsv() const;								//����ע����Ϣ��string��ʽ��
	bool operator==(const user&) const;						//�Ƿ��û�����ͬ��ע��ʱ���ã�
private:
	string username;	//�û���
	string password;	//����
	bool isAdmin;		//�Ƿ��ǹ���Ա
public:
	friend istream& operator>>(istream& i, user& u) {		//��������ȡ������������������
		string tmp;
		getline(i, u.username, ',');
		getline(i, u.password, ',');
		getline(i, tmp);
		u.isAdmin = (tmp=="����Ա");
		return i;
	}
	friend ostream& operator<<(ostream& o, const user& u) {	//����������������������������
		o << (u.username + "," + u.password + "," + (u.isAdmin ? "����Ա" : "�û�"));
		return o;
	}
};

#endif
