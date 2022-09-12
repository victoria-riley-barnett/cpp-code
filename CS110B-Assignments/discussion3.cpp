// Assignment1: Riley Barnett
// This program calculates grades

#include <iostream>
using namespace std;

//Prototype functions
double toCelsius(double);
double toFarenheit(double);

int main() {
    double celsiusConv, farenheitConv, temp, newTempF, newTempC;
    char typeFlag; 

    cout << "Enter your temperature: ";
    cin >> temp;
    cout << "Is your temperature in Farenheit (f) or Celsius (c)? (f/c)";
    cin >> typeFlag;

    if (typeFlag == 'c') {
	    cout << "Your converted temperature is: " << toFarenheit(temp) << " Farenheit" << endl;
    }
    else if (typeFlag == 'f') {
	    cout << "Your converted temperature is: " << toCelsius(temp) << " Celsius" << endl;
    }
    else {
        cout << "Please flag your temperature as Farenheit or Celsius using f or c";
        cin >> typeFlag;
    }

    cout << "F \tC" << endl;

    for (int i = 60; i <= 80; i++) {
        cout << i << "\t" << toCelsius(i) << "\n";
    }

    return 0;
}

double toCelsius(double farenheit) {
    float celsiusConv;

    celsiusConv = (5 * (farenheit - 32)) / 9;

    return celsiusConv;

}

double toFarenheit(double celsius) {
    float farenheitConv;

    farenheitConv = ((9 * celsius) / 5) + 32;

    return farenheitConv;
}
