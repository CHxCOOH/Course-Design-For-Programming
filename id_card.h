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
	void editName(string Name);				//�޸�����
	void editGender(string Gender);			//�޸��Ա�
	void editAddress(string Address);		//�޸ĵ�ַ
	void editNation(string Nation);			//�޸�����
	void editBirthdate(string Birthdate);	//�޸ĳ�������
	void updateCard();						//�޸İ�����ֹ����
	void markDeath();						//�������
	unsigned long long getId();				//�������֤�ţ��޷��ų����ͣ�
	const string& getName() const;			//����������string��ʽ��
	const string& getId() const;			//�������֤�ţ�string��ʽ��
	const string& getGender() const;		//�����Ա�string��ʽ��
	const string& getAddress() const;		//���ص�ַ��string��ʽ��
	const string& getNation() const;		//�������壨string��ʽ��
	const string& getBirthdate() const;		//���س������ڣ�string��ʽ��
	const string& getStartdate() const;		//���ذ������ڣ�string��ʽ��
	const string& getEnddate() const;		//���ؽ�ֹ���ڣ�string��ʽ��
	string getInfo() const;			//�������֤��Ϣ��string��ʽ��Tab�ָ���
	bool operator<(const id_card& o) const;	//����С�ںţ���������
	bool operator>(const id_card& o) const;	//���ش��ں�
	bool operator==(const id_card& o) const;//���ع�ϵ�����
	bool operator!=(const id_card& o) const;//���ع�ϵ�����
	bool operator<=(const id_card& o) const;//���ع�ϵ�����
	bool operator>=(const id_card& o) const;//���ع�ϵ�����
private:
	string id;					//���֤�ţ�string��ʽ��
	unsigned long long id_int64;//���֤�ţ������ͣ�
	string name;				//����			
	string gender;				//�Ա�string����/Ů��
	bool isMale;				//�Ա�bool��
	string address;				//��ַ
	string nation;				//����
	string birthdate;			//��������
	string startdate;			//��������
	string enddate;				//��ֹ����

	friend ostream& operator<<(ostream& o, const id_card& id) {	//������֤��Ϣ��csv��ʽ�����ŷָ���
		o << id.id + "," + id.name + "," + id.gender + "," + id.nation + "," + id.birthdate + "," + id.startdate + "," + id.enddate + "," + id.address;
		return o;
	}
friend istream& operator>>(istream& i, id_card& id) {	//�������֤��Ϣ����csv�ļ������У�
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
	id.isMale = id.gender == "��";
	return i;
}
};

#endif