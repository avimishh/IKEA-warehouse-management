#ifndef __Size_h
#define __Size_h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Size{
	double width;
	double height;
	double depth;
public:
	//sets and gets
	double getWidth() const{ return width; };
	double getHeight() const{ return height; };
	double getDepth() const{ return depth; };
	void setWidth(double width) ;
	void setHeight(double height);
	void setDepth(double depth) ;
	//c'tors
	Size();
	Size(double, double, double) ;
	//methods
	void print() const;
	void setSize(double, double, double) ;
	const Size& change(double dx, double dy, double dz);
	//operators
	const Size& operator+(const Size& o);
	bool operator==(const Size& o) const;
	friend ostream& operator<<(ostream& os, const Size& o);
	friend istream& operator>>(istream& in, Size& o);
	friend int checkNegative(double x);
};
#endif