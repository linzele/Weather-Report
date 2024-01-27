#ifndef array_variable_H
#define array_variable_H
#include <iostream>
using namespace std;

struct array_variable
{
    int h,v;
    int id;
    string city;
    int cloud_value, cloud_index, pressure, pressure_index;
    char cloudcover_LMH, pressure_LMH;
    bool used;
} **ary;

#endif
