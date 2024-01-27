#include <iostream>
#include <string>

using namespace std;

vector<string> tokenize_string(string input, string delimit)
{
        size_t pos = 0;
        string token;
        vector<string> result;

        while ((pos = input.find(delimit)) != string::npos)
        {
            token = input.substr(0, pos);
            result.push_back(token); 
            input.erase(0, pos + delimit.length());
        }
        
	result.push_back(input);

        return (result);
}
