#define _CRT_SECURE_NO_WARNINGS
#ifndef __Furniture_h
#define __Furniture_h
#include <iostream>
#include "Size.h"

using namespace std;

class Furniture {
protected:
	char* name;
	char* materialType;
	Size size;
	double price;
	static double mostExpensiveEver;
	friend class WareHouse;
public:
	//gets and sets
	const char* getName() const { return name; } ;
	const char* getMaterialType()const { return materialType; } ;
	const Size& getSize()  const { return size; } ;
	double getPrice() { return price; };
	void setName(char *name);
	void setMaterialType(char *materialType);
	void setSize(const Size& size);
	void setPrice(double price);
	//c'tors
	Furniture();
	Furniture(char* name, char* materialType, Size size, double price);
	Furniture(const Furniture& o);
	virtual ~Furniture();
	//methods
	virtual void print() const;
	void changeSize(double dx,double dy,double dz);
	virtual void upgrade() =0;
	//operators
	const Furniture& operator=(const Furniture& o);
	bool operator==(const Furniture& o);
	friend ostream& operator<<(ostream& os, const Furniture& o);
	//friend istream& operator>>(istream& in, Furniture& o);
	//static
	static void setMostExpensive(const Furniture& o);
	static double getMostExpensive();
};

#endif