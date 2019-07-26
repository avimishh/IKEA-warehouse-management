#include "Size.h"
#include<iostream>
using namespace std;

int checkNegative(double x)
{
	if (x < 0)
		return 0;
	else 
		return 1;
}
 
void Size::setWidth(double width) {
	checkNegative(width);
	this->width = width;
}
void Size::setHeight(double height)  {
	checkNegative(height);
	this->height = height;
}
void Size::setDepth(double depth) {
	checkNegative(depth);
	this->depth = depth;
}


//c'tors
Size::Size() :width(0), height(0), depth(0) {}
Size::Size(double width, double height, double depth)  {
	setSize(width, height, depth);
}
//methods
void Size::setSize(double width, double height, double depth)  {
	setWidth(width);
	setHeight(height);
	setDepth(depth);
}
const Size& Size::change (double dx, double dy, double dz) {
	width += dx;
	height += dy;
	depth += dz;
	return *this;
}
void Size::print() const {
	cout << *this;
}
//operators
const Size& Size::operator+(const Size& o) {
	(*this).change(o.width, o.height, o.depth);
	return *this;
}
bool Size::operator==(const Size& o) const {
	if (width == o.width)
		if (height == o.height)
			if (depth == o.depth)
				return true;
	return false;
}

ostream& operator<<(ostream& os, const Size& o) {
	os <<"Size: "<< o.width <<"*"<< o.height <<"*"<< o.depth << "[m*m*m]";
	return os;
}

istream& operator >> (istream& in, Size& o) {
	in >> o.width >> o.height >> o.depth;
	return in;
}
