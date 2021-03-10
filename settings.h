//公用头文件
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
const char* userfile = "users.dat"; //用户信息文件名
const char* datafile = "data.csv";	//身份信息文件名
const char* deathfile = "death.dat";//死亡信息文件名
const char* userFileHead = "用户名,密码,类别";	//用户信息表头
const char* dataFileHead = "身份证号,姓名,性别,民族,出生日期,办理日期,截止日期,地址";	//身份信息表头
const char* line = " ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────";	//分隔线
};

#endif
