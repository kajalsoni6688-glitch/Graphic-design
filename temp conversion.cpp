#include <iostream>
using namespace std;
int main() {
    double temperature, celsius, fahrenheit, kelvin;
    char unit;
    cout << "===== Temperature Conversion Program =====" << endl;
    cout << "Enter temperature value: ";
    cin >> temperature;
    cout << "Enter unit (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;
    if (unit == 'C' || unit == 'c') {
        fahrenheit = (temperature * 9.0 / 5.0) + 32;
        kelvin = temperature + 273.15;
        cout << "\nConverted Temperatures:" << endl;
        cout << "Celsius: " << temperature << " °C" << endl;
        cout << "Fahrenheit: " << fahrenheit << " °F" << endl;
        cout << "Kelvin: " << kelvin << " K" << endl;
    }
    else if (unit == 'F' || unit == 'f') {
        celsius = (temperature - 32) * 5.0 / 9.0;
        kelvin = celsius + 273.15;
        cout << "\nConverted Temperatures:" << endl;
        cout << "Fahrenheit: " << temperature << " °F" << endl;
        cout << "Celsius: " << celsius << " °C" << endl;
        cout << "Kelvin: " << kelvin << " K" << endl;
    }
    else if (unit == 'K' || unit == 'k') {
        celsius = temperature - 273.15;
        fahrenheit = (celsius * 9.0 / 5.0) + 32;
        cout << "\nConverted Temperatures:" << endl;
        cout << "Kelvin: " << temperature << " K" << endl;
        cout << "Celsius: " << celsius << " °C" << endl;
        cout << "Fahrenheit: " << fahrenheit << " °F" << endl;
    }
    else {
        cout << "Invalid unit! Please enter C, F, or K." << endl;
    }

    return 0;
}