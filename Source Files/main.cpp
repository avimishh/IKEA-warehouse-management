#include "Furniture.h"
#include "Seat.h"
#include "Size.h"
#include "Storage.h"
#include "Table.h"
#include "WareHouse.h"


int main_menu() {
	int act;
	cout << "\n-------Menu:---------\n";
	cout << "1 - build a new furniture\t 5 - what is the most expesive furniture\n";
	cout << "2 - break an exist furniture\t 6 - print all furniture built\n";
	cout << "3 - upgrade furniture\t\t 7 - exit\n";
	cout << "4 - check the price";
	cout << "\n\t\tPress your choice (1,2...) -> ";
	cin >> act;
	return act;
}

int build_menu() {
	int act;
	cout << "\n----Build Menu----\nchoose type of furniture:\n1>Table\n2>Seat\n3>Storage\n";
	cout << "\t\tPress your choice (1,2...) -> ";
	cin.ignore();
	cin >> act;
	return act;
}

Furniture* init_furnuiture_details(int furniture_id) {
	Furniture* tmp = NULL;
	Size tmp_size;
	char name[20], material[20], design[20];
	double price;
	int num;
	cin.ignore();
	cout << "Furniture details " << "\n>Name: "; cin.getline(name, 20);
	cout << ">Material: "; cin.getline(material, 20); cout << ">Price: ";
	cin.ignore();
	cin >> price; cout << ">Size(wd,hi,de): "; cin >> tmp_size;
	switch (furniture_id) {
	case 1:
		cin.ignore();
		cout << ">Number of seats: "; cin >> num;
		cout << ">Purpose: "; cin.ignore(); cin.getline(design, 20);
		tmp = new Table(name, material, tmp_size, price, num, design);
		break;
	case 2:
		cout << ">Padding type: "; cin.ignore(); cin.getline(design, 20);
		tmp = new Seat(name, material, tmp_size, price, design);
		break;
	case 3:
		int drawers, shelfs;
		cin.ignore();
		cout << ">Number of drawers: "; cin >> drawers;
		cin.ignore();
		cout << ">Number of shelfs: "; cin >> shelfs;
		cout << ">Design: "; cin.ignore(); cin.getline(design, 20);
		tmp = new Storage(name, material, tmp_size, price, drawers, shelfs, design);
		break;
	default:
		break;
	}
	return tmp;
}

Furniture* more_options(Furniture* tmp) {
	char str[20];
	cout << "\nbefore we add this furniture to stock do you want to change something?";
	cout << "\npress your choice (yes/no)-> ";
	cin.ignore();
	cin.getline(str, 20);
	if (!strncmp(str, "yes", 3))
	{
		if (typeid(*tmp) == typeid(Table)) {
			((Table*)tmp)->increaseSeats();
			cout << "number of seats will increased.";
		}
		if (typeid(*tmp) == typeid(Seat)) {
			((Seat*)tmp)->removePadding();
			cout << "padding removed.\n";
		}
		if (typeid(*tmp) == typeid(Storage)) {
			((Storage*)tmp)->shelfToDrawer();
			cout << "shelf converted to drawer.\n";
		}
	}
	return tmp;
}

WareHouse destroy_furniture(WareHouse ware_hosue) {
	char str[20];
	ware_hosue.catalog();
	cout << "\nWhich Furniture you want to destroy? ";
	cin.ignore();
	cin.getline(str, 20);
	if (ware_hosue.deleteFurniture(str))
		cout << "\nfurniture destroyed\n";
	else cout << "\nthere is no furniture correspond of this name\n";
	return ware_hosue;
}

void main() {
	char str[20];
	WareHouse IKEA(5);
	int act = 0;
	Furniture* tmp = NULL;
	cout << "Hello! Wellcome to your Furniture Data base.";
	while (1) {
		switch (main_menu()) {
		case 1:
			act = build_menu();
			tmp = init_furnuiture_details(act);
			tmp = more_options(tmp);

			IKEA.addFurniture(tmp) ? cout << "\n\n!!!!!!! new Furniture created !!!!!!!!\n\n"
				: cout << "\n\n!!!!!!!!! no more space in the warehouse !!!!!!!!\n\n";
			break;
		case 2:
			IKEA.catalog();
			cout << "\nWhich Furniture you want to destroy? ";
			cin.ignore();
			cin.getline(str, 20);
			if (IKEA.deleteFurniture(str))
				cout << "\nfurniture destroyed\n";
			else cout << "\nthere is no furniture correspond of this name\n";
			break;
		case 3:
			IKEA.catalog();
			cout << "\nWhat you want to upgrade? ";
			cin.ignore();
			cin.getline(str, 20);
			IKEA.upgradeFurniture(str) ? cout << "\nupgrade succeed\n" : cout << "\ntask not completed\n";
			break;
		case 4:
			IKEA.catalog();
			cout << "\nWhat interesting you? ";
			cin.ignore();
			cin.getline(str, 20);
			cout << "The price of " << str << ": " << IKEA.checkPrice(str) << endl;
			break;
		case 5:
			cout << "\nThe most expensive Furniture ever price: ";
			cout << Furniture::getMostExpensive() << endl;
			break;
		case 6:
			cout << IKEA << endl;
			break;
		case 7:
			return;
			break;
			//	default:
		}
		system("cls");
	}
}