#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "array_size.h"
#include "array_variable.h"
#include "processFile.h"
#include "displayCityMap.h"
#include "displayCloudIndex.h"
#include "displayCloudSymbol.h"
#include "displayPressureIndex.h"
#include "displayPressureSymbol.h"
#include "report.h"

using namespace std;

void displayMenu();
void displayCityMap(int,int);
void displayCloudIndex(int,int);
void displayCLoudSymbol(int,int);
void displayPressureIndex(int,int);
void displayPressureSymbol(int,int);


void displayMenu() {
	cout << "ID   : #INPUT YOUR ID" << endl;
 	cout << "NAME : #INPUT YOUR NAME" << endl;
	cout << "--------------------------------" << endl;
	cout << "Welcome to Weather Information Processing System!" << endl;
	cout << endl;
 	cout << "1)   Read in and process a configuration file" << endl;
	cout << "2)   Display city map" << endl;
    	cout << "3)   Display cloud coverage map (cloudiness index)" << endl;
    	cout << "4)   Display cloud coverage map (LMH symbols)" << endl;
    	cout << "5)   Display atmospheric pressure map (pressure index)" << endl;
    	cout << "6)   Display atmospheric pressure map (LMH symbols)" << endl;
    	cout << "7)   Show weather forecast summary report" << endl;
    	cout << "8)   Quit" << endl;
    	cout << endl;
    	cout << "Please enter your choice: "; 
}

int main () 
{
	int menuOptions;

	while ( menuOptions != 8) {

        		displayMenu();
            	cin >> menuOptions;
            	cout << endl;

            	switch (menuOptions) {

                	case 1:
                    		**ary = readAndProcessFile();
                    		break;

		        case 2:
				displayCityMap(array_size.hori, array_size.vert);
		            	break;

		        case 3:
		            	displayCloudIndex(array_size.hori, array_size.vert);
		            	break;

		        case 4:
		            	displayCloudSymbol(array_size.hori, array_size.vert);
		            	break;

		        case 5:
		            	displayPressureIndex(array_size.hori, array_size.vert);
		            	break;

		        case 6:
		            	displayPressureSymbol(array_size.hori, array_size.vert);
		            	break;

		        case 7:
		            	report(array_size.hori, array_size.vert);
		            	break;
		            
		        case 8:
		        	cout << "Thank You" << endl;
		        	break;
                
                default:
                    	cout << "Invalid choice. Please select options 1 to 7 or option 8." << endl;
                    	cout << "-----------------------------------------" << endl;
                    	cout << endl;
            }
}


	
	if(array_size.vert <= 0) {	 
		for(int i = 0; i < array_size.hori; i ++) {		
			delete[] ary [i];
		}
		delete [] ary;
	}
	return 0;
}

