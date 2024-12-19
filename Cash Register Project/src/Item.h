/*
 * Item.h
 *
 *  Created on: Mar 27, 2023
 *      Author: glv1003
 */
#include <iostream>
using namespace std;

#ifndef ITEM_H_
#define ITEM_H_


class Item {

private:
	int qty;
	double cost;
	string name;
	int soldqty;

public:
	Item();
	Item(int, double, string);

	void setqty(int);
	int getqty();
	void setcost(double);
	double getcost();
	void setname(string);
	string getname();
	void setsoldqty(int);
	int getsoldqty();


};

#endif /* ITEM_H_ */
