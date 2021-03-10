//�˵���UI
#pragma once
#ifndef MENU_H
#define MENU_H

#include "settings.h"

class menu {
public:
	menu();
	void entryMenu() const;					//��¼/ע�����
	void entryMenu0() const;				//�״�ע��ҳ��
	void registerHint() const;				//�û��������ʽ��ʾ
	void registerLenInvalid() const;		//�û������볤�ȴ���
	void registerUserAlreadyExist() const;	//�û����Ѵ���
	void registerSuccess() const;			//ע��ɹ�
	void loginHint1() const;				//��¼��ʾ�������û�����
	void loginHint2() const;				//��¼��ʾ���������룩
	void loginSuccess() const;				//��¼�ɹ�
	void loginFailed() const;				//��¼ʧ��
	void logoutSuccess() const;				//�ǳ��ɹ�
	void displayUsersHint() const;			//��ʾ�����û���ʾ
	void displayUsersEditHint() const;		//������û�������ʾ
	void userIndexHint() const;				//�����û������ʾ
	void userIndexError() const;			//�û���ŷǷ�
	void editUserHint() const;				//�༭�û���ʾ
	void editUserMenu(bool isadmin) const;	//�༭�û�ѡ��
	void editUsernameHint() const;			//�༭�û�����ʾ
	void editPasswordHint() const;			//�༭������ʾ
	void editUserSuccess() const;			//�༭�û��ɹ�
	void editFailed() const;				//�༭�û�ʧ��
	void functionMenu(bool isAdmin) const;	//���ܲ˵�ҳ��
	void addId_cardHint() const;			//��������Ϣ��ʾ
	void addId_cardHint2() const;			//��������Ϣ��ʾ
	void addId_cardAlreadyExist() const;	//���֤���ظ�����
	void addIdSuccess() const;				//��ӳɹ�
	void queryIdHint() const;				//��ѯ�����Ϣ��ʾ
	void querySuccess() const;				//��ѯ�ɹ�
	void querIdEditHint() const;			//��ѯ����������ʾ
	void queryId_cardHint() const;			//ģ����ѯ��ʾ
	void queryFuzzySuccess(int n) const;	//ģ����ѯ�ɹ�
	void idNotFound() const;				//���֤�Ų�����
	void sortHint() const;					//���������Ϣ��ʾ
	void sortidSuccess() const;				//����ɹ�
	void markDeathHint() const;				//ע�������Ϣ��ʾ
	void markedSuccess() const;				//ע���ɹ�
	void displayId_cardHint() const;		//��ʾ������Ϣ��ʾ
	void pause() const;						//����̨��ͣ
	void editId_cardHint() const;			//�༭�����Ϣ��ʾ
	void editId_cardOption() const;			//�༭��Ŀѡ��
	void editSuccess() const;				//�༭�ɹ�
	void editNameHint() const;				//�༭������ʾ
	void editGenderHint() const;			//�༭�Ա���ʾ
	void editNationHint() const;			//�༭������ʾ
	void editAddressHint() const;			//�༭��ַ��ʾ
	void editBirthHint() const;				//�༭������ʾ
	void deleteId_cardHint() const;			//ɾ�������Ϣ��ʾ
	void deleteSuccess() const;				//ɾ���ɹ�
	void exportSuccess() const;				//�����ɹ�
private:
	void printLogo() const;					//��������ӡϵͳLOGO
};

#endif
