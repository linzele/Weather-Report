#ifndef border_h
#define border_h

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void printBorder(int column) {
	for (int i=0; i< column+ 4; i++)
	{
    		if (i == 0)
        	{
            		cout << setw(4) << "  ";
        	}
        	else
        	{
        	    cout << setw(3) << "# ";
        	} 
    	}
    	cout << endl;
}

#endif
