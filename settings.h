//����ͷ�ļ�
#pragma once
#ifndef SETTING_H
#define SETTING_H
#pragma warning(disable:4996)

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>
#include <conio.h>
using namespace std;

struct Settings {
const char* userfile = "users.dat"; //�û���Ϣ�ļ���
const char* datafile = "data.csv";	//�����Ϣ�ļ���
const char* deathfile = "death.dat";//������Ϣ�ļ���
const char* userFileHead = "�û���,����,���";	//�û���Ϣ��ͷ
const char* dataFileHead = "���֤��,����,�Ա�,����,��������,��������,��ֹ����,��ַ";	//�����Ϣ��ͷ
const char* line = " ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";	//�ָ���
};

#endif
