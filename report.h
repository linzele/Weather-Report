#ifndef report_H
#define report_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int print_City (int,int,vector <int> ,int);
double rain_Probability(char, char);
void rain_ASCII(double);

void report(int hori, int vert)
{
	cout << "Weather Forecast Summary Report" << endl;
    	cout << "------------------------------" << endl;

	vector <int> cityid;     	

    	for (int h = 0; h < hori + 1; h++) {
		for (int v = 0; v < vert + 1; v++) {
		    	if (ary[h][v].used == true) {
		        	cityid.push_back({ary[h][v].id});
			}
		}
	}

	sort(cityid.begin(),cityid.end(),greater<int>());

    	cityid.erase(unique(cityid.begin(), cityid.end()), cityid.end());

	for (int i = 0; i < cityid.size(); i++) 
	    {
		double grid_area = 0;
		double cloud_sum = 0;
		double cloud_avg = 0;
		double pressure_sum = 0;
		double pressure_avg = 0;

		for (int x = 0; x < hori + 1; x++)
		{
		    for (int y = 0; y < vert + 1; y++)
		    {
		    	if (ary[x][y].id == cityid[i])
		        {
		            grid_area++;
		            cloud_sum += ary[x][y].cloud_value;
		            pressure_sum += ary[x][y].pressure;
		        }

		        // Top
		        else if (y + 1 <= vert && ary[x][y + 1].id == cityid[i])
		        {
		            grid_area++;
		            cloud_sum += ary[x][y].cloud_value;
		            pressure_sum += ary[x][y].pressure;
		        }

		        // Top Left
		        else if (y + 1 <= vert && x - 1 <= hori && x - 1 >= 0 && ary[x - 1][y + 1].id == cityid[i])
		        {
		            grid_area++;
		            cloud_sum += ary[x][y].cloud_value;
		            pressure_sum += ary[x][y].pressure;
		        }

		        // Top Right
		        else if (y + 1 <= vert && x + 1 <= hori && ary[x + 1][y + 1].id == cityid[i])
		        {
		            grid_area++;
		            cloud_sum += ary[x][y].cloud_value;
		            pressure_sum += ary[x][y].pressure;
		        }

		        // Left
		        else if (x - 1 <= hori && x - 1 >= 0 && ary[x - 1][y].id == cityid[i])
		        {
		            grid_area++;
		            cloud_sum += ary[x][y].cloud_value;
		            pressure_sum += ary[x][y].pressure;
		        }

		        // Right
		        else if (x + 1 <= hori && ary[x + 1][y].id == cityid[i])
		        {
		            grid_area++;
		            cloud_sum += ary[x][y].cloud_value;
		            pressure_sum += ary[x][y].pressure;
		        }

		        // Bottom
		        else if (y - 1 >= 0 && ary[x][y - 1].id == cityid[i])
		        {

		            grid_area++;
		            cloud_sum += ary[x][y].cloud_value;
		            pressure_sum += ary[x][y].pressure;
		        }

		        // Bottom Left
		        else if (y - 1 >= 0 && x - 1 <= hori && x - 1 >= 0 && ary[x - 1][y - 1].id == cityid[i])
		        {
		            grid_area++;
		            cloud_sum += ary[x][y].cloud_value;
		            pressure_sum += ary[x][y].pressure;
		        }

		        // Bottom Right
		        else if (y - 1 >= 0 && x + 1 <= hori && ary[x + 1][y - 1].id == cityid[i])
		        {
			    grid_area++;
		            cloud_sum += ary[x][y].cloud_value;
		            pressure_sum += ary[x][y].pressure;
		        }

			else {

			}
		    }
		}

		cloud_avg = cloud_sum / grid_area;
		pressure_avg = pressure_sum / grid_area;

		print_City(hori,vert,cityid, i);
		cout << "City ID" << setw(5) << ": " << cityid[i] << endl; 
		cout << "Ave. Cloud Cover (ACC)" << setw(4) << ": " << fixed << setprecision(2) << cloud_avg    << " (" << get_char((int)cloud_avg)    << ")" << endl;
		cout << "Ave. Pressure (AP)" << setw(8) << ": "  << fixed << setprecision(2) << pressure_avg << " (" << get_char((int)pressure_avg) << ")" << endl;
		
		double rain_chance = rain_Probability(get_char((int)cloud_avg), get_char((int)pressure_avg)); 
		cout << "Probability of Rain (%)" << setw(3) << ": " << fixed << setprecision(2) << rain_chance << endl;
		rain_ASCII(rain_chance);
		cout << endl;
	    }
}

int print_City(int hori, int vert, vector<int>cityid, int i)
{
    for (int horiarr = 0; horiarr < hori + 1; horiarr++)
    {
        for (int vertarr = 0; vertarr < vert + 1; vertarr++)
        {
            if (ary[horiarr][vertarr].id == cityid[i]) 
            {
                cout << "City Name : " << ary[horiarr][vertarr].city << endl;
                return (0);
            }
        }
    }
    return (0);
}

double rain_Probability(char cloud_avg, char pressure_avg)
{
	if (cloud_avg == 'H' && pressure_avg == 'L') {
        	return (90);
	}

    	else if (cloud_avg == 'M' && pressure_avg == 'L') {
        	return (80);
	}

    	else if (cloud_avg == 'L' && pressure_avg == 'L') {
        	return (70);
	}

    	else if (cloud_avg == 'H' && pressure_avg == 'M') {
        	return (60);
	}

    	else if (cloud_avg == 'M' && pressure_avg == 'M') {
        	return (50);
	}
	
    	else if (cloud_avg == 'L' && pressure_avg == 'M') {
        	return (40);
	}

    	else if (cloud_avg == 'H' && pressure_avg == 'H') {
        	return (30);
	}

    	else if (cloud_avg == 'M' && pressure_avg == 'H') {
        	return (20);
	}

    	else {
        	return (10);
	}
}

void rain_ASCII(double rain_chance)
{
	if (rain_chance == 90) {
		cout << "~~~~" << endl;
		cout << "~~~~~" << endl;
		cout << "\\\\\\\\\\" << endl;
    	}

    	else if (rain_chance == 80) {
        	cout << "~~~~" << endl;
        	cout << "~~~~~" << endl;
        	cout << setw(1) << "\\\\\\\\" << endl;
    	}

    	else if (rain_chance == 70) {
        	cout << "~~~~" << endl;
        	cout << "~~~~~" << endl;
        	cout << setw(2) << "\\\\\\" << endl;
	}

    	else if (rain_chance == 60) {
        	cout << "~~~~" << endl;
        	cout << "~~~~~" << endl;
        	cout << setw(3) << "\\\\" << endl;
    	}

    	else if (rain_chance == 50) {
        	cout << "~~~~" << endl;
        	cout << "~~~~~" << endl;
        	cout << setw(4) <<"\\" << endl;
    	}

    	else if (rain_chance == 40) {
        	cout << "~~~~" << endl;
        	cout << "~~~~~" << endl;
    	}

    	else if (rain_chance == 30) {
        	cout << "~~~" << endl;
        	cout << "~~~~" << endl;
    	}

    	else if (rain_chance == 20) {
        	cout << "~~" << endl;
        	cout << "~~~" << endl;
    	}
    	
	else {
        	cout << "~" << endl;
        	cout << "~~" << endl;
    	}	
}


#endif
