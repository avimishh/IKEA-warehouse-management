#ifndef __WareHouse_h
#define __WareHouse_h
#include <iostream>
#include "Size.h"
#include "Furniture.h"
#include "Seat.h"
#include "Storage.h"
#include "Table.h"
using namespace std;

class WareHouse {
protected:
	Furniture** stock;
	const int maxSizeOfStock;
	int size;
public:
	//gets and sets
//	const Furniture* getStock() const { return *stock; };
	void setStock(Furniture** stock);
	//c'tors
	WareHouse(int maxSizeOfStock = 5);
	WareHouse(Furniture** stock,int maxSizeOfStock);
	WareHouse(const WareHouse & o);
	~WareHouse();
	//methods
	bool addFurniture(Furniture* o);
	bool deleteFurniture(char* toDelete);
	bool upgradeFurniture(char* toUpgrade);
	double checkPrice(char* toCheck);
	void print();
	friend int findMember(const WareHouse& o, char* name);
	void catalog();
	//operators
	friend ostream& operator<<(ostream& os, const WareHouse& o);
	bool operator+(Furniture* o);
	const WareHouse& operator=(const WareHouse& o);

};







#endif