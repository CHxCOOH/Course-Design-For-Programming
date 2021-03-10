#include "id_card.h"

id_card::id_card() {
}

id_card::id_card(string ID) : id(ID) {
}

id_card::id_card(unsigned long long ID) : id_int64(ID) {
	stringstream ss;
	ss << ID;
	ss >> id;
}

id_card::id_card(string ID, string Name, string Gender, string Address, string Nation, string Birthdate):
  id(ID), name(Name), gender(Gender), isMale(Gender=="ÄĞ"), 
  address(Address), nation(Nation), birthdate(Birthdate)	{
	if ( ID[17] != 'X' && ID[17] != 'x' )
		id_int64 = stoull(ID);
	else {
		stringstream ss(ID);
		ss >> id_int64;
	}
	updateCard();
}

id_card::id_card(string ID, string Name, bool ismale, string Address, string Nation, string Birthdate) :
	id(ID), name(Name), gender(ismale?"ÄĞ":"Å®"), isMale(ismale),
	address(Address), nation(Nation), birthdate(Birthdate)	{
	if ( ID[17] != 'X' && ID[17] != 'x' )
		id_int64 = stoull(ID);
	else {
		stringstream ss(ID);
		ss >> id_int64;
	}
	updateCard();
}

unsigned long long id_card::getId() {
	return id_int64;
}

const string& id_card::getName() const {
	return name;
}

const string& id_card::getId() const {
	return id;
}

const string& id_card::getGender() const {
	return gender;
}

const string& id_card::getAddress() const {
	return address;
}

const string& id_card::getNation() const {
	return nation;
}

void id_card::editName(string Name) {
	name = Name;
	updateCard();
}

void id_card::editGender(string Gender) {
	gender = Gender;
	isMale = Gender=="ÄĞ";
	updateCard();
}

void id_card::editAddress(string Address) {
	address = Address;
	updateCard();
}

void id_card::editNation(string Nation) {
	nation = Nation;
	updateCard();
}

void id_card::editBirthdate(string Birthdate) {
	birthdate = Birthdate;
	updateCard();
}

void id_card::updateCard() {
	time_t rawtime = time(NULL);
	char datestr[80];
	tm* pTm = localtime(&rawtime);
	
	strftime(datestr, 80, "%Y-%m-%d", pTm);
	startdate = datestr;
	
	int birthYear;
	stringstream stream;
	stream << birthdate;
	stream >> birthYear;

	if ( pTm->tm_year - birthYear >= 18 ) {
		pTm->tm_year += 10;
	} else {
		pTm->tm_year += 5;
	}

	strftime(datestr, 80, "%Y-%m-%d", pTm);
	enddate = datestr;
}

void id_card::markDeath() {
	time_t rawtime = time(NULL);
	char datestr[80];
	tm* pTm = localtime(&rawtime);

	strftime(datestr, 80, "%Y-%m-%d", pTm);
	enddate = startdate = datestr;
}

const string& id_card::getBirthdate() const {
	return birthdate;
}

const string& id_card::getStartdate() const {
	return startdate;
}

const string& id_card::getEnddate() const {
	return enddate;
}

string id_card::getInfo() const {
	stringstream ss;
	ss << left << setw(20) << id << setw(8) << name << setw(6) << gender << setw(6) << nation << setw(12) << birthdate << setw(12) << startdate << setw(12) << enddate << setw(42) << address;
	return ss.str();
}

bool id_card::operator<(const id_card& o) const {
	return id_int64 < o.id_int64;
}

bool id_card::operator>(const id_card& o) const {
	return o < *this;
}

bool id_card::operator==(const id_card& o) const {
	return id_int64 == o.id_int64;
}

bool id_card::operator>=(const id_card& o) const {
	return !(*this < o);
}

bool id_card::operator<=(const id_card& o) const {
	return !(*this > o);
}

bool id_card::operator!=(const id_card& o) const {
	return !(*this == o);
}
