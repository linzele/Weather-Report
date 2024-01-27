#ifndef displayCloudIndex_H
#define displayCloudIndex_H

#include <iostream>
#include <string>
#include <sstream>
#include "border.h"
#include "number.h"

using namespace std;

void printBorder(int);
void printNumber(int);

void displayCloudIndex(int x, int y)
{

	printBorder(x);

        for (int row=y; row>=0; row--)
        {   
                ostringstream oss;
                oss << setw(3) << row << setw(3) << "#";

                for (int col=0; col<=x; col++)
                {
                    oss << setw(3) << ary[col][row].cloud_index;
                }

                oss << setw(3) << " #" << endl;
                cout << oss.str();
        }

	printBorder(x);
	
	printNumber(x);	

}

#endif
