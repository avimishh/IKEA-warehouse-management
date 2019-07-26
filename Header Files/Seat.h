#ifndef __Seat_h
#define __Seat_h
#include <iostream>
#include "Size.h"
#include "Furniture.h"
using namespace std;

class Seat : public Furniture {
protected:
	char* paddingType;
public:
	//gets and sets
	const char* getPaddingType() { return paddingType; };
	void setPaddingType(char* paddingType);
	//c'tors
	Seat();
	Seat(char* name, char* materialType, Size size, double price, char* paddingType);
	Seat(const Seat&o);
	virtual ~Seat();
	//methods
	virtual void upgrade();
	virtual void print() const;
	void removePadding();
	//operators
	friend ostream& operator<<(ostream& os, const Seat& o);
	const Seat& operator=(const Seat&o);
	bool operator==(const Seat&o);
};

#endif