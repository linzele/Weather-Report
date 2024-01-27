#ifndef number_H
#define number_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printNumber(int column) {
	for (int i=0; i< column + 2; i++)
    	{
        	if (i == 0)
        	{
        	    cout << setw(6) << " ";
        	}
        	else
        	{
        	    cout << setw(3) << i-1;
        	}
    	}
    	cout << endl;
    	cout << endl;
}

#endif
