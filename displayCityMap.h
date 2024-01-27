#ifndef displayCityMap_H
#define displayCityMap_H

#include <iostream>
#include <sstream>
#include "border.h"
#include "number.h"

using namespace std;

void printBorder(int);
void printNumber(int);

void displayCityMap(int x, int y)
{
	
	printBorder(x);	

    	for (int row=y; row>=0; row--)
    	{   
		ostringstream oss;
    		oss << setw(3) << row << setw(3) << "#";

    		for (int col=0; col<=x; col++)
                {
                        if (ary[col][row].used == true)
                            oss << setw(3) << ary[col][row].id;
                        else {
                            oss << setw(3) << " ";
			}                
		}

                oss << setw(3) << " #" << endl;
                cout << oss.str();
        }

	
	printBorder(x);

	printNumber(x);
}

#endif
