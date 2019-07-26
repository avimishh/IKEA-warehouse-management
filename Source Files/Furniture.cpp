#include "Furniture.h"

double Furniture::mostExpensiveEver=0;
void Furniture::setMostExpensive(const Furniture& o) {
	if (mostExpensiveEver == 0) {
		mostExpensiveEver = o.price;
	}
	if (mostExpensiveEver< o.price)
		mostExpensiveEver = o.price;
}
double Furniture::getMostExpensive() {
	return mostExpensiveEver;
}


//gets and sets
void Furniture::setName(char *name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Furniture::setMaterialType(char *materialType) {
	this->materialType = new char[strlen(materialType) + 1];
	strcpy(this->materialType, materialType);
}
void Furniture::setSize(const Size& size) {
	this->size.operator=(size);
}
void Furniture::setPrice(double price) {
	this->price = price;
}
//c'tors
Furniture::Furniture() :size(), price(0) {
	char* tmp;
	tmp = new char('-');
	setName(tmp);
	setMaterialType(tmp);
}
Furniture::Furniture(char* name, char* materialType, Size size, double price) :
	size(size), price(price) {
	setName(name);
	setMaterialType(materialType);
	setMostExpensive(*this);
}
Furniture::Furniture(const Furniture& o): size(o.size) {
	name = NULL;
	materialType = NULL;
	*this = o;
}
Furniture::~Furniture() {
	delete[] name;
	delete[] materialType;
}
//methods
void Furniture::print() const {
	cout << *this;
}
void Furniture::changeSize(double dx, double dy, double dz) {
	size.change(dx, dy, dz);
}
//operators
const Furniture& Furniture::operator=(const Furniture& o) {
	if (this != &o) {
		delete[] name;
		delete[] materialType;
		setName(o.name);
		setMaterialType(o.materialType);
		size = o.size;
		price = o.price;
	}
	return *this;
}
ostream& operator<<(ostream& os, const Furniture& o) {
	os << "\n>Name: " << o.name << "\n>Material: " << o.materialType 
		<<"\n>Size: " << o.size <<"\n>price: " << o.price;
	return os;
}
/*istream& operator >> (istream& in, Furniture& o) {
	char name[20], materialType[20], manufactur[20];
	in >> "\n>Name: " >> name >> ">Material: " >> materialType >> ">Manufactor: "
		>> manufactur >> ">Size: " >> o.size >> ">cost: " >> o.price;
	o.setName(name);
	o.setMaterialType(materialType);
	return in;
}
*/
bool Furniture::operator==(const Furniture& o) {
	if (!strcmp(name, o.name))
		if (!strcmp(materialType, o.materialType))
				if (size == o.size)
					if (price == o.price)
						return true;
	return false;
}