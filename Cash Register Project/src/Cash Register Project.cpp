//============================================================================
// Name        : CashRegisterProject.cpp
// Author      : Griffin Vasalani, Grant Riley, Josh Janney
// Description : This program displays a store for customers to purchase items.
//============================================================================

//password is 1234 if you are the manager

#include <iostream>
#include <fstream>
#include "Item.h"
#include "Money.h"
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	Money Register;
	Item tempItem;
	vector <Item> Inv;
	int tempQty;
	double tempcost;
	string tempname;
	ifstream inFile;
	int option = 0;
	double total = 0;
	double totalgiven = 0;
	int numpennys=0, numdimes=0, numquarters=0, numnickels=0, numones=0, numtens=0, numfives=0, numtwenties=0;
	double change = 0;
	double tw=0, t=0, f=0, o=0, q=0, n=0, d=0, p=0;
	bool endofday = false;
	int password = 1;
	int anwser = 0;
	double changebeinggiven;
	double originalchange;

	for (int i=0; i<Inv.size(); i++)
	{
		Inv.at(i).setsoldqty(0);
	}

	inFile.open("Final.txt");
	if (inFile.fail())
	{
		cout << "File not found\n";
		return 0; // exit (1);
	}
	while (!inFile.eof())
	{
		inFile >> tempQty;
		inFile >> tempcost;
		getline(inFile, tempname);
		tempItem.setqty(tempQty);
		tempItem.setcost(tempcost);
		tempItem.setname(tempname);
		Inv.push_back(tempItem);

	}

do{

	bool continue_shopping = true;
			while (continue_shopping && total <= 119.99) {
			for(int i =0; i<Inv.size(); i++)
				{
					cout << i + 1 << " " << Inv.at(i).getcost() << " " << Inv.at(i).getname() << endl;
					}
	    cout << "Enter 'c' to continue shopping or 'e' to end purchase: ";
	    char choice;
	    cin >> choice;
	    if (choice == 'e') {
	        continue_shopping = false;
	    } else if (choice == 'c') {

	        cout << "Enter the number for the item that you would like to purchase: ";
	        cin >> option;
	        while(option > Inv.size() || option < 1){
	        	cout << "Error. Please enter another item: ";
	        	cin >> option;
	        }
	        while (Inv.at(option-1).getqty() < 1)
	        {
	        	cout << endl << "We are out of that Item. Sorry. Please select another item: ";
	        	cin >> option;
	        }
	        cout << endl << "You have selected: " << Inv.at(option-1).getname();
	        total = total + Inv.at(option-1).getcost();
	        cout << endl << "Your total is: " << total << endl;
	        for (int i =0; i<Inv.size(); i++){
	        	if(Inv.at(i).getname() == Inv.at(option-1).getname()){
	        		Inv.at(i).setqty(Inv.at(i).getqty() -1);
	        	}
	        	if(Inv.at(i).getname() == Inv.at(option-1).getname()){
	        		    Inv.at(i).setsoldqty(Inv.at(i).getsoldqty() + 1);
	        	}
	        }
	    } else {
	        cout << "Invalid choice. Please try again." << endl << endl;
	    }
	}
if(total > 0){
	cout << endl << "Your final total is: " << total;

	cout << endl << "Enter how many twenties you will be paying with: ";
	cin >> numtwenties;
	Register.settwenties(Register.gettwenties() + numtwenties);

	cout << endl << "Enter how many tens you will be paying with: ";
	cin >> numtens;
	Register.settens(Register.gettens() + numtens);

	cout << endl << "Enter how many fives you will be paying with: ";
	cin >> numfives;
	Register.setfives(Register.getfives() + numfives);

	cout << endl << "Enter how many ones you will be paying with: ";
	cin >> numones;
	Register.setones(Register.getones() + numones);

	cout << endl << "Enter how many quarters you will be paying with: ";
	cin >> numquarters;
	Register.setquarters(Register.getquarters() + numquarters);

	cout << endl << "Enter how many dimes you will be paying with: ";
	cin >> numdimes;
	Register.setdimes(Register.getdimes() + numdimes);

	cout << endl << "Enter how many nickels you will be paying with: ";
	cin >> numnickels;
	Register.setnickels(Register.getnickels() + numnickels);

	cout << endl << "Enter how many pennies you will be paying with: ";
	cin >> numpennys;
	Register.setpennys(Register.getpennys() + numpennys);

	totalgiven = numtwenties * 20 + numtens * 10 + numfives * 5 + numones * 1 + numquarters *.25 + numdimes * .1 + numnickels * .05 + numpennys * .01;
	if (totalgiven < total)
	{
		cout << endl << "You have not given enough. You have only given: $" << totalgiven << " Your change has been returned." << endl;
		totalgiven =0;
		Register.settwenties(Register.gettwenties() - numtwenties);
		Register.settens(Register.gettens() - numtens);
		Register.setfives(Register.getfives() - numfives);
		Register.setones(Register.getones() - numones);
		Register.setquarters(Register.getquarters() - numquarters);
		Register.setdimes(Register.getdimes() - numdimes);
		Register.setnickels(Register.getnickels() - numnickels);
		Register.setpennys(Register.getpennys() - numpennys);
	}

    if(totalgiven >= total){

	change = totalgiven - total;
	originalchange = totalgiven - total;

	cout << endl << "You have given a total of: $" << totalgiven;
	cout << endl << "Your change will be: $" << change << endl;

	tw = static_cast<int>(change /20);
	change -= tw *20;
	if(Register.gettwenties() >= tw){
 	   Register.settwenties(Register.gettwenties() - tw);
	}
	else{
		change += (tw - Register.gettwenties()) *20;
		tw = Register.gettwenties();
		Register.settwenties(0);
	}

	t = static_cast<int>(change /10);
	change -= t *10;
	if(Register.gettens() >= t){
	Register.settens(Register.gettens() - t);
	}
	else{
		change += (t - Register.gettens())*10;
		t = Register.gettens();
		Register.settens(0);
	}

	f = static_cast<int>(change /5);
	change -= f *5;
	if(Register.getfives() >= f){
		Register.setfives(Register.getfives() - f);
	}
	else{
		change += (f - Register.getfives())* 5;
		f = Register.getfives();
		Register.setfives(0);
	}

	o = static_cast<int>(change /1);
	change -= o *1;
	if(Register.getones() >= o){
	Register.setones(Register.getones() - o);
	}
	else{
		change += (o - Register.getones())* 1;
		o = Register.getones();
		Register.setones(0);
	}

	q = static_cast<int>(change /.25);
	change -= q *.25;
	if(Register.getquarters() > q){
	Register.setquarters(Register.getquarters() - q);
	}
	else {
		change += (q - Register.getquarters())*.25;
		q = Register.getquarters();
		Register.setquarters(0);
	}

	d = static_cast<int>(change /.1);
	change -= d *.1;
	if(Register.getdimes() > d){
	Register.setdimes(Register.getdimes() - d);
	}
	else{
		change += (d - Register.getdimes()) * .1;
		d = Register.getdimes();
		Register.setdimes(0);
	}

	n = static_cast<int>((change /.05));
	change -= n * .05;
	if(Register.getnickels() > n){
	Register.setnickels(Register.getnickels() - n);
	}
	else{
		change += (n - Register.getnickels()) * .05;
		n = Register.getnickels();
		Register.setnickels(0);
	}

	p = static_cast<int>(round(change /.01));
	change -= p*.01;
	if(Register.getpennys() > p){
	Register.setpennys(Register.getpennys() - p);
	}
	else{
		change += (p - Register.getpennys())*.01;
		p = Register.getpennys();
		Register.setpennys(0);
	}

	changebeinggiven = tw*20 + t*10 + f*5 + o*1 + q*.25 + d*.1 + n*.05 + p*.01;

	if((int)(originalchange * 100) > (int)(changebeinggiven * 100))
	{
		cout << endl << "The cash register only has $" << changebeinggiven << " to give you.";
		cout << endl << "We are giving you your money back. " << endl << endl;
		Register.settwenties(Register.gettwenties() - numtwenties);
		Register.settens(Register.gettens() - numtens);
		Register.setfives(Register.getfives() - numfives);
		Register.setones(Register.getones() - numones);
		Register.setquarters(Register.getquarters() - numquarters);
		Register.setdimes(Register.getdimes() - numdimes);
		Register.setnickels(Register.getnickels() - numnickels);
		Register.setpennys(Register.getpennys() - numpennys);
		Register.settwenties(Register.gettwenties() + tw);
		Register.settens(Register.gettens() + t);
		Register.setfives(Register.getfives() + f);
		Register.setones(Register.getones() + o);
		Register.setquarters(Register.getquarters() + q);
		Register.setdimes(Register.getdimes() + d);
		Register.setnickels(Register.getnickels() + n);
		Register.setpennys(Register.getpennys() + p);
	}

	else {
	cout << "Here is how you are receiving the change: " << endl;
	cout << "Twenties " << tw << endl;
	cout << "Tens: " << t << endl;
	cout << "Fives: " << f << endl;
	cout << "Ones: " << o << endl;
	cout << "Quarters: " << q << endl;
	cout << "Dimes " << d << endl;
	cout << "Nickels: " << n << endl;
	cout << "Pennies: " << p << endl;
	cout << "Your transaction is over." << endl << endl;
    }
}
}
	cout << "If you are the manager enter the password.";
	cout << endl << "Enter a 1 if you are not the manager to return to the main menu: ";
	cin >> password;
	while (password != 1234 && password !=1){
		{
			cout << endl << "Error. Please either enter password if you are manager.";
			cout << endl << "Enter a 1 if you are not the manager to return to the main menu: ";
			cin >> password;
		}
	}
	if(password == 1234)
	{
		cout << "If you would like to end the day enter a 1, if enter a 0: ";
		cin >> anwser;
		while (anwser != 1 && anwser !=0){
			cout << endl << "Error. Please Enter a 1 to end the day." << endl;
			cout << "Enter a 0 to return to the menu and continue shopping: " << endl;
			cin >> anwser;
		}
			if (anwser == 1)
			{
				endofday = true;
			}
			else
				endofday = false;
	}
	else
	{
		endofday = false;
	}

total = 0;

}while(endofday != true);


cout << endl << "Here is how many bills and coins the register has: " << endl;
cout << "Twenties: " << Register.gettwenties() << endl;
cout << "Tens: " << Register.gettens() << endl;
cout << "Fives: " << Register.getfives() << endl;
cout << "Ones: " << Register.getones() << endl;
cout << "Quarters: " << Register.getquarters() << endl;
cout << "Dimes: " << Register.getdimes() << endl;
cout << "Nickels: " << Register.getnickels() << endl;
cout << "Pennies: " <<  Register.getpennys() << endl;

ofstream outFile("report.txt");

outFile << "Here is how much of each you have sold: " << endl;
for(int i =0; i<Inv.size(); i++)
{
	outFile << Inv.at(i).getsoldqty() << " " << Inv.at(i).getcost() << " " << Inv.at(i).getname() << endl;
}
outFile << endl << endl << "Here is the Inventory: " << endl;
for(int i =0; i<Inv.size(); i++)
{
	outFile << Inv.at(i).getqty() << " " << Inv.at(i).getcost() << " " << Inv.at(i).getname() << endl;
}
outFile.close();

	return 0;
}
