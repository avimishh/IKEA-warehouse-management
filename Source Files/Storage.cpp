#include "Storage.h"


void Storage::setDesign(char* design) {
	this->design = new char[strlen(design) + 1];
	strcpy_s(this->design,strlen(design)+1, design);
}


//c'tors
Storage::Storage() :Furniture(), numOfDrawers(0), numOfShelfs(0) {};
Storage::Storage(char* name, char* materialType,
	Size size, double price, int numOfDrawers, int numOfShelfs, char* design) :
	Furniture(name, materialType, size, price), numOfDrawers(numOfDrawers),
	numOfShelfs(numOfShelfs) {
	setDesign(design);
};
Storage::Storage(const Storage&o) :Furniture(o) {
	setDesign(o.design);
	numOfDrawers = o.numOfDrawers;
	numOfShelfs = o.numOfShelfs;
}
Storage::~Storage() {
	delete[] design;
}
//methods
void Storage::upgrade() {
	if(shelfToDrawer())
		price += 50;
	else cout << "no more upgrade for storage";
}
bool Storage::shelfToDrawer() {
	if (numOfShelfs > 0) {
		numOfShelfs--;
		numOfDrawers++;
		return true;
	}	
	return false;
}
void Storage::print() const {
	cout << *this;
}
//operators
ostream& operator<<(ostream& os, const Storage& o) {
	os << (Furniture&)o << "\n>Number of drawers: " << o.numOfDrawers
		<< "\n>Number of shelfs: " << o.numOfShelfs<<"\n>Design: "<<o.design;
	return os;
}
/*istream& operator >> (istream& in, Storage& o) {
	in >> (Furniture&)o >> ">Number of drawers: " >> o.numOfDrawers >> ">Number of shelfs: " >> o.numOfShelfs;
	return in;
}*/
const Storage& Storage::operator=(const Storage&o) {
	if (this != &o) {
		(Furniture&)*this = o;
		//	Furniture::operator=(o);
		delete[] design;
		setDesign(o.design);
		numOfDrawers = o.numOfDrawers;
		numOfShelfs = o.numOfShelfs;
	}
	return *this;
}

bool Storage::operator==(const Storage&o) {
	if (Furniture::operator==(o))
		if (!strcmp(design, o.design))
			if (numOfDrawers == o.numOfDrawers)
				if(numOfShelfs==o.numOfShelfs)
				return true;
	return false;
}

void Storage::operator++() {
	numOfDrawers++;
	numOfShelfs++;
}