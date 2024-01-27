#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "array_size.h"
#include "array_variable.h"
#include "tokenize_string.h"

using namespace std;

vector<string> string_token(string, string);

array_variable processFile();
array_variable openFile(string);
array_variable openFile_pressure(string);
char get_char(int);

array_variable readAndProcessFile()
{
	string filename;
	
	cout << "[ Read in and process a configuration file ]" << endl;

	do {
		cout << "Please enter config filename: ";
		cin >> filename;

		if (filename != "config.txt") {
			cout << endl <<"Incorrect filename! Please Re-enter" << endl;
		}

	} while (filename != "config.txt");

	ifstream in_data;
 	fstream inFile(filename.c_str(), fstream::in);

 	string aLine;
 	cout << endl;
	if(inFile.is_open())
 	{
    		while (!inFile.eof())
    		{
         		(getline(inFile, aLine));

         		if(aLine[0] == '/' && aLine[1] == '/') 
         		{

         		}

        		else if (aLine.find("GridX_IdxRange") != string::npos)
                	{

            			string horiline = aLine.erase(0, 15); 
                	        vector<string> horinum = tokenize_string(horiline, "-"); 
                	        array_size.hori = atoi(horinum[1].c_str());
                	        cout << "Reading in GridX_IdxRange : " << aLine << " ... done!" << endl;
                	        horinum.clear();

                	}
                
			else if (aLine.find("GridY_IdxRange") != string::npos)
                	{
	                       string vertline = aLine.erase(0, 15); 
			       vector<string> vertnum = tokenize_string(vertline, "-"); 
	                       array_size.vert = atoi(vertnum[1].c_str());
	                       cout << "Reading in GridY_IdxRange : " << aLine << " ... done!" << endl;
	                       vertnum.clear();
	                       cout << endl;
	                }
                	if (array_size.hori != 0 && array_size.vert != 0) {
                       	       break;
			}
        	}

        	ary = new array_variable * [array_size.hori + 1];
        	for (int i = 0; i < array_size.hori + 1; i++) {
            		ary[i] = new array_variable[array_size.vert + 1];
        	}
		for (int horiarr = 0; horiarr < array_size.hori + 1; horiarr++) {
            		for (int vertarr = 0; vertarr < array_size.vert + 1; vertarr++) {
                		ary[horiarr][vertarr].h = horiarr;
                		ary[horiarr][vertarr].v = vertarr;
            		}
        	}

        	int i = 0;
        	cout << "Storing data from input file :";
        	while (getline(inFile, aLine))
        	{
            		size_t pos = aLine.find(".txt");
            		if (pos != string::npos) {
                		if (i == 0)
                		{
                    			**ary = openFile(aLine);
                    			cout << aLine << " ...done!";
                		}
                		
				else if (i == 1)
                		{
                    			**ary = openFile(aLine);
                    			cout << aLine << " ...done!" << endl;
                		}
                
				else if (i == 2)
               			{
                    			**ary = openFile_pressure(aLine);
                    			cout << aLine << " ...done!" << endl;
                		}
            			
				i++;
            		}
        	}
        	cout << endl;
        	cout << "All records succesfully stored. Going back to main menu..." << endl;
        	cout << endl;
        	inFile.close();
	}
	
	else {
		cout << "Error";
	}

    	return **ary;
}

array_variable openFile(string filename)
{
        fstream inFile(filename.c_str(), fstream::in);
    	string aLine;
    	string storageLine;
    	while (getline(inFile, aLine))
    	{
        	if (aLine == "") {
            		break;
		}
        	aLine.erase(0, 1); 

        	vector<string> hori = tokenize_string(aLine, ", ");
        	int horiG = atoi(hori[0].c_str());
        	storageLine = hori[1];
       
        	vector<string> vert = tokenize_string(storageLine, "]");
        	int vertG = atoi(vert[0].c_str());
        	storageLine = vert[1];
        	storageLine = storageLine.erase(0, 1); 

        	if (storageLine.size() == 2) {
            		int cloud_value = stoi(storageLine);
            
            		storageLine = storageLine.substr(0, 1);
           		
			int cloud_index = stoi(storageLine);
            		char cloudcover_LMH = get_char(cloud_value);
            
            		ary[horiG][vertG].cloud_value = cloud_value;
            		ary[horiG][vertG].cloud_index = cloud_index;
           		ary[horiG][vertG].cloudcover_LMH = cloudcover_LMH;
        	}
        
		else if (storageLine.size() == 1) {
            
            		int cloud_value = stoi(storageLine);
            
            		int cloud_index = 0;
            
            		char cloudcover_LMH = get_char(cloud_value);
            
            		ary[horiG][vertG].cloud_value = cloud_value;
            		ary[horiG][vertG].cloud_index = cloud_index;
            		ary[horiG][vertG].cloudcover_LMH = cloudcover_LMH;

		}

        	else {	
            		vector<string> third_value = tokenize_string(storageLine, "-");
            
            		int id = atoi(third_value[0].c_str());
		    	storageLine = third_value[1];
		    
		    	string city = storageLine;
		    
		    	ary[horiG][vertG].id = id;
		    	ary[horiG][vertG].used = true;
		    	ary[horiG][vertG].city = city;
		}
	    }
    
    	cout << endl;
    	return **ary;
}

char get_char(int cloud_or_pressure) {
	if (cloud_or_pressure < 35) {
		return ('L');
	}
    
	else if (cloud_or_pressure >= 35 && cloud_or_pressure < 65) {
	        return ('M');
	}
	
	else {
        	return ('H');	
	}
}

array_variable openFile_pressure(string filename)
{
    	fstream inFile(filename.c_str(), fstream::in);
    	string aLine;
	string storageLine;
    	while (getline(inFile, aLine))
    	{
        	if (aLine == "") {
            		break;
		}
		
        	aLine.erase(0, 1); 
		vector<string> horinum = tokenize_string(aLine, ", "); 
		int horiarr = atoi(horinum[0].c_str());
		storageLine = horinum[1];
		vector<string> vertnum = tokenize_string(storageLine, "]"); 
		int vertarr = atoi(vertnum[0].c_str());
		storageLine = vertnum[1];
		storageLine = storageLine.erase(0, 1); 
		if (storageLine.size() == 2) {
		    
		    int pressure = stoi(storageLine);
		    
		    storageLine = storageLine.substr(0, 1);
		    int pressure_index = stoi(storageLine);
		    
		    char pressure_LMH = get_char(pressure);
		    
		    ary[horiarr][vertarr].pressure = pressure;
		    ary[horiarr][vertarr].pressure_index = pressure_index;
		    ary[horiarr][vertarr].pressure_LMH = pressure_LMH;
		}

		else {
		    
		    int pressure = stoi(storageLine);
		    
		    int pressure_index = 0;
		    
		    char pressure_LMH = get_char(pressure);
		    
		    ary[horiarr][vertarr].pressure = pressure;
		    ary[horiarr][vertarr].pressure_index = pressure_index;
		    ary[horiarr][vertarr].pressure_LMH = pressure_LMH;
		}
	}
    	return **ary;
}
