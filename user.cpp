#include "user.h"

user::user():username(""), password(""), isAdmin(0) {
}

user::user(string initName, string initPass, bool isadmin):username(initName), password(initPass), isAdmin(isadmin) {
}

bool user::login(string usernm, string passwd) const {
	return usernm==username && passwd==password ? true : false;
}

void user::changeUsername(string newUsername) {
	username = newUsername;
}

void user::changePassword(string newPassword) {
	password = newPassword;
}

const string& user::getUsername() const {
	return username;
}

const string& user::getPassword() const {
	return password;
}

void user::updagePrivs() {
	isAdmin = true;
}

bool user::isadmin() const {
	return isAdmin;
}

string user::getInfoCsv() const {
	return username + "," + password + "," + (isAdmin ? "管理员":"用户");
}

bool user::operator==(const user& r) const {
	return username == r.username;
}
