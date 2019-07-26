#include "WareHouse.h"





int findMember(const WareHouse& o, char* name) {
	int i = 0;
	while (strcmp(o.stock[i][0].getName(), name))
	{
		if (i+1 < o.size)
			i++;
		else
			return -1;
	}
	return i;
}

void WareHouse::setStock(Furniture ** stock)
{
	this->stock = stock;
}
//c'tors
WareHouse::WareHouse(int maxSizeOfStock): maxSizeOfStock(maxSizeOfStock)
{
	this->stock = new Furniture*[maxSizeOfStock];
//	this->maxSizeOfStock = maxSizeOfStock;
	size = 0;
}
WareHouse::WareHouse(Furniture ** stock, int size):maxSizeOfStock(maxSizeOfStock)
{
//	this->maxSizeOfStock = size;
	this->size = size;
	setStock(stock);
	//this->stock = new Furniture*[maxSizeOfStock];
}
WareHouse::WareHouse(const WareHouse & o):maxSizeOfStock(o.maxSizeOfStock)
{
	stock = NULL;
	*this = o;
}
WareHouse::~WareHouse()
{
	for (int i = 0; i < size; i++)
		delete stock[i];
	delete[] stock;
}
//methods
bool WareHouse::addFurniture(Furniture* o)
{
	return *this+o;
}

bool WareHouse::deleteFurniture(char* toDelete)
{
	int i = findMember(*this, toDelete);
	if (i == -1)
		return false;
	delete stock[i];
	for (i; (i+1) < size; i++) {
		stock[i] = stock[i + 1];
	}
	size--;
	return true;
	
}

bool WareHouse::upgradeFurniture(char* toUpgrade)
{
	int i = findMember(*this, toUpgrade);
	if (i == -1)
		return false;
	stock[i][0].upgrade();
}

double WareHouse::checkPrice(char* toCheck)
{
	int i = findMember(*this, toCheck);
	if (i == -1)
		return -1;
	//return false;
	return stock[i][0].price;
}

void WareHouse::print()
{
	cout << *this;
}

void WareHouse::catalog()
{
	cout << "\n";
	for (int i = 0; i < size; i++) {
		cout <<"#"<<i+1<<" "<< stock[i][0].name<<"   ";
	}
}

bool WareHouse::operator+(Furniture* o)
{
	if (size < maxSizeOfStock) {
		stock[size] = o;
		size++;
		return true;
	}
	return false;
}

const WareHouse & WareHouse::operator=(const WareHouse & o)
{
	if (this != &o) {
		delete stock;
		stock = o.stock;
		size = o.size;
//		maxSizeOfStock = o.maxSizeOfStock;
	}
	return *this;
}

ostream & operator<<(ostream & os, const WareHouse & o)
{
	os << "\n>Size: " << o.size << "\n--------Stock: \n";
	for (int i = 0; i < o.size; i++) {
		cout << "\n#" << i + 1;
		o.stock[i][0].print();
	}
	return os;
}
