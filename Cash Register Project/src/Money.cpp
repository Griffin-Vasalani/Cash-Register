/*
 * Money.cpp
 *
 *  Created on: Mar 27, 2023
 *      Author: glv1003
 */

#include "Money.h"
#include <iostream>
using namespace std;

Money::Money() {
	setpennys(50);
	setnickels(40);
	setdimes(50);
	setquarters(40);
	setones(10);
	setfives(10);
	settens(10);
	settwenties(10);

}
void Money :: setpennys(int pennys)
{
	this->pennys = pennys;
}
int Money :: getpennys()
{
	return this->pennys;
}
void Money :: setnickels(int nickels)
{
	this->nickels = nickels;
}
int Money :: getnickels()
{
	return this->nickels;
}
void Money :: setdimes(int dimes)
{
	this->dimes = dimes;
}
int Money :: getdimes()
{
	return this->dimes;
}
void Money :: setquarters(int quarters)
{
	this->quarters = quarters;
}
int Money :: getquarters()
{
	return this->quarters;
}
void Money :: setones(int ones)
{
	this->ones = ones;
}
int Money :: getones()
{
	return this->ones;
}
void Money :: setfives(int fives)
{
	this->fives = fives;
}
int Money :: getfives()
{
	return this->fives;
}
void Money :: settens(int tens)
{
	this->tens = tens;
}
int Money :: gettens()
{
	return this->tens;
}
void Money :: settwenties(int twenties)
{
	this->twenties = twenties;
}
int Money :: gettwenties()
{
	return this->twenties;
}

