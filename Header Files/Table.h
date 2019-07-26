#ifndef __Table_h
#define __Table_h
#include <iostream>
#include "Size.h"
#include "Furniture.h"
using namespace std;

class Table : public Furniture {
protected:
	int numOfSeats;
	char* purpose;
public:
	//gets and sets
	int getNumOfSeats() { return numOfSeats; };
	const char* setPurpose() { return purpose; };
	void setNumOfSeats(int numOfSeats) { this->numOfSeats = numOfSeats; };
	void setPurpose(char* purpose);
	//c'tors
	Table();
	Table(char* name, char* materialType, Size size, double price, int numOfSeats, char* purpose);
	Table(const Table&o);
	virtual ~Table();
	//methods
	virtual void upgrade();
	virtual void print() const;
	void increaseSeats();
	//operators
	friend ostream& operator<<(ostream& os, const Table& o);
	friend istream& operator >> (istream& in, Table& o);
	const Table& operator=(const Table&o);
	bool operator==(const Table&o);
	void operator++();
};
#endif