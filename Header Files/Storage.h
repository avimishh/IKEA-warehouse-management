#ifndef __Storage_h
#define __Storage_h
#include <iostream>
#include "Size.h"
#include "Furniture.h"
using namespace std;

class Storage : public Furniture {
protected:
	char* design;
	int numOfDrawers;
	int numOfShelfs;
public:
	//gets and sets
	int getnumOfDrawers() { return numOfDrawers; };
	int getnumOfShelfs() { return numOfShelfs; };
	const char* getDesign() { return design; };
	void setDesign(char* design);
	void setnumOfDrawers(int numOfDrawers) { this->numOfDrawers=numOfDrawers; };
	void setnumOfShelfs(int numOfShelfs) { this->numOfShelfs=numOfShelfs; };
	//c'tors
	Storage();
	Storage(char* name, char* materialType, Size size,
		double price, int numOfDrawers, int numOfShelfs, char* design);
	Storage(const Storage&o);
	virtual ~Storage();
	//methods
	virtual void upgrade();
	bool shelfToDrawer();
	virtual void print() const;
	//operators
	friend ostream& operator<<(ostream& os, const Storage& o);
	const Storage& operator=(const Storage&o);
	bool operator==(const Storage&o);
	void operator++();
};

#endif
