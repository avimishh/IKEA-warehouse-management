#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"

void Table::setPurpose(char* purpose) {
	this->purpose = new char[strlen(purpose) + 1];
	strcpy(this->purpose, purpose);
}

//c'tors
Table::Table() :numOfSeats(0), Furniture() {
	char* tmp = new char[sizeof "-"];
	std::strcpy(tmp, "-");
	setPurpose(tmp);
};
Table::Table(char* name, char* materialType, Size size,
	double price, int numOfSeats, char* purpose) :numOfSeats(numOfSeats),
	Furniture(name, materialType, size, price) {
	setPurpose(purpose);
};
Table::Table(const Table&o) :Furniture(o) {
	setPurpose(o.purpose);
	numOfSeats = o.numOfSeats;
}
Table::~Table() {
	delete[] purpose;
}
//methods
void Table::upgrade() {
	numOfSeats += 2;
	size.change(20, 0, 0);
}
void Table::print() const {
	cout << *this;
}
void Table::increaseSeats()
{
	upgrade();
}
//operators
ostream& operator<<(ostream& os, const Table& o) {
	os << (Furniture&)o << "\n>Number of seats: " << o.numOfSeats<<"\n>purpose: " <<o.purpose;
	return os;
}

const Table& Table::operator=(const Table&o) {
	if (this != &o) {
		(Furniture&)*this = o;
		//	Furniture::operator=(o);
		delete[] purpose;
		setPurpose(o.purpose);
		numOfSeats = o.numOfSeats;
	}
	return *this;
}

bool Table::operator==(const Table&o) {
	if (Furniture::operator==(o))
		if (!strcmp(purpose, o.purpose))
			if(numOfSeats==o.numOfSeats)
			return true;
	return false;
}

void Table::operator++() {
	upgrade();
}