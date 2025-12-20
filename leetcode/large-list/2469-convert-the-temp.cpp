#include <bits/stdc++.h>
using namespace std;

//Kelvin = Celsius + 273.15
//Fahrenheit = Celsius * 1.80 + 32.00

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius+273.15, celsius*1.8+32};
    }
};

