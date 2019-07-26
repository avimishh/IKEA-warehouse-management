#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h"
#include <string>

void Seat::setPaddingType(char* paddingType) {
	this->paddingType = new char[strlen(paddingType) + 1];
	strcpy_s(this->paddingType,strlen(paddingType)+1, paddingType);
}

//c'tors
Seat::Seat() : Furniture() {
	char* tmp;
	tmp = new char('-');
	setPaddingType(tmp);
}
Seat::Seat(char* name, char* materialType, Size size,
	double price, char* paddingType) : Furniture(name, materialType, size, price) {
	setPaddingType(paddingType);
}
Seat::Seat(const Seat&o):Furniture(o) {
	setPaddingType(o.paddingType);
}
Seat::~Seat() {
	delete[] paddingType;
}
//methods
void Seat::upgrade() {
	strcpy_s(paddingType,5, "GOLD");
	price += 100;
}
void Seat::print() const {
	cout << *this;
}
void Seat::removePadding()
{
	delete[] paddingType;
	char* tmp = new char[sizeof "no padding"];
	std::strcpy(tmp, "no padding");
	setPaddingType(tmp);
}
//operators
ostream& operator<<(ostream& os, const Seat& o) {
	os << (Furniture&)o << "\n>Padding type: " << o.paddingType;
	return os;
}
/*istream& operator >> (istream& in, Seat& o) {
	char paddingType[20];
	in >> (Furniture&)o >> "\n>Padding type: " >> paddingType;
	strcpy(o.paddingType, paddingType);
}*/
const Seat& Seat::operator=(const Seat&o) {
	if (this != &o) {
		(Furniture&)*this = o;
	//	Furniture::operator=(o);
		delete[] paddingType;
		setPaddingType(o.paddingType);
	}
	return *this;
}

bool Seat::operator==(const Seat&o) {
	if (Furniture::operator==(o))
		if (!strcmp(paddingType, o.paddingType))
			return true;
	return false;
}