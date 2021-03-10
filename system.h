//��UI��Ĳ�������
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
	void sysEntry();				//ϵͳ��ں���
private:
	int activeUser;					//��ǰ�Ĺ���Ա�û�
	linkedList<user> users;			//�����û��б�
	vector<id_card> id_cards;		//�������֤��Ϣ
private:
	void sysFuncs();				//ϵͳ������					
	void addId_cardInfo();			//��Ӹ�����Ϣ
	void deleteId_card();			//ɾ��������Ϣ�������֤�ţ�
	void editId_card();				//�༭������Ϣ�������֤�ţ�
	void markForDeath();			//��������������֤�ţ�
	void queryId();					//��ѯ������Ϣ�������֤�ţ�
	void queryId_cardFuzzy() const;	//��ѯ������Ϣ��ģ�����ң�
	void displayUsers();			//��ʾ�����û�
	void sortId_card();				//����
	void exportToFile() const;		//����������Ϣ
private:
	void initFile();								//�״δ�ʱ��ʼ���ļ�
	void readFromFile();							//���ļ���ȡ����
	void Register();								//ע��
	void login();									//��¼
	void logout();									//�ǳ�
	bool deleteUser(int index);						//ɾ��ָ���û�
	bool updateUserPriv(int index);					//������ͨ�û�Ȩ��
	void editUser();								//�����û���Ϣ
	void editUser(int index);						//�����û���Ϣ�����±꣩
	bool updateUsername(int index, string newName);	//�����û���
	bool updatePassword(int index, string newPass);	//��������
	void displayId_cards() const;					//��ʾ���������Ϣ
	void deleteId_card(vector<id_card>::iterator it);						//ɾ��ָ����Ϣ
	void editId_card(vector<id_card>::iterator it);							//�༭ָ����Ϣ
	void updateCard(vector<id_card>::iterator it);							//���¿�Ƭ
	void updateName(vector<id_card>::iterator it);							//��������
	void updateGender(vector<id_card>::iterator it);						//�����Ա�
	void updateAddress(vector<id_card>::iterator it);						//���ĵ�ַ
	void updateNation(vector<id_card>::iterator it);						//��������
	void updateBirthdate(vector<id_card>::iterator it);						//���ĳ�������
	void sortById();														//�����֤������
	void sortByIdDesc();													//�����֤�Ž���
	void sortbyName();														//����������
	void markForDeath(vector<id_card>::iterator it);						//���ָ���������
	void exportId_cardToFile() const;										//������Ϣ���ļ����ɴ�ӡ��
	void exportUsersToFile() const;											//�����û����ļ�
	void writeToDeath(const id_card& i);									//д�������������Ϣ���ļ�
	bool isIndexLegel(int index) const;										//����û��±��Ƿ�Ϸ�
	bool strIdcard(vector<id_card>::const_iterator it, string str) const;	//ģ������str�Ƿ������ָ�������Ϣ��
	vector<id_card>::iterator findId(unsigned long long id_ull);			//������֤���Ƿ����
	vector<id_card>::const_iterator findId(unsigned long long id_ull) const;//������֤���Ƿ����
};

#endif
