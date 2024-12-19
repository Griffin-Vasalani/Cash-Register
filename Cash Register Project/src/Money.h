/*
 * Money.h
 *
 *  Created on: Mar 27, 2023
 *      Author: glv1003
 */

#ifndef MONEY_H_
#define MONEY_H_
#include <iostream>

class Money {
private:
	int pennys;
	int nickels;
	int dimes;
	int quarters;
	int ones;
	int fives;
	int tens;
	int twenties;

public:
	Money();
	void setpennys(int);
	int getpennys();
	void setnickels(int);
	int getnickels();
	void setdimes(int);
	int getdimes();
	void setquarters(int);
	int getquarters();
	void setones(int);
	int getones();
	void setfives(int);
	int getfives();
	void settens(int);
	int gettens();
	void settwenties(int);
	int gettwenties();
};

#endif /* MONEY_H_ */
