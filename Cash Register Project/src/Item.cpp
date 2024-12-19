/*
 * Item.cpp
 *
 *  Created on: Mar 27, 2023
 *      Author: glv1003
 */

#include "Item.h"

Item::Item() {
	setqty(0);
	setsoldqty(0);

}
void Item :: setqty(int qty)
{
	this->qty = qty;
}
int Item :: getqty()
{
	return this->qty;
}
void Item :: setcost(double cost)
{
	this->cost = cost;
}
double Item :: getcost()
{
	return this->cost;
}
void Item :: setname(string name)
{
	this->name = name;
}
string Item :: getname()
{
	return this->name;
}
void Item:: setsoldqty(int soldqty)
{
	this->soldqty = soldqty;
}
int Item :: getsoldqty()
{
	return this->soldqty;
}
