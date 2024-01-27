#ifndef displayPressureSymbol_H
#define displayPressureSymbol_H

#include <iostream>
#include "border.h"
#include "number.h"

using namespace std;

void printBorder(int);
void printNumber(int);

void displayPressureSymbol(int x, int y)
{
	printBorder(x);

    	for (int row=y; row>=0; row--)
    	{   
        	ostringstream oss;
        	oss << setw(3) << row << setw(3) << "#";

        	for (int col=0; col<=x; col++)
        	{
        	    oss << setw(3) << ary[col][row].pressure_LMH;
        	}

        	oss << setw(3) << " #" << endl;
        	cout << oss.str();
    	}

	printBorder(x);

	printNumber(x);

}

#endif
