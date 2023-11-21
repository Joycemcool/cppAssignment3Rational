#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include "../inc/Rational.h"

//Helper function
bool isNullOrWhitespace(const string& str) {
    return str.empty()
           || all_of(str.begin(), str.end(), [](char c) {
        return isspace(static_cast<unsigned char>(c));
    });
}

int main() {

    cout << "Hello, World!" << endl;
    //Declare variables
    string inputPrompt1 = "Please input first Rational number, seperated by ',' if both numerator denominator provided";
    string inputPrompt2 = "Please input second Rational number, seperated by ',' if both numerator denominator provided";
    string stringInput1;
    int rational1;
    string stringInput2;
    int rational2;

    Rational a;  // Default constructor
    Rational b(5);  // One Argument constructor
    Rational c(3, 4);  // Two Argument constructor
    Rational d("-1/2");  // String constructor

    //Test rational value
    cout<< a <<endl;
    cout<< b <<endl;
    cout<< c <<endl;
    cout<< d <<endl;

    //Ask for input
    do{
        cout << inputPrompt1 <<endl;
        getline(cin,stringInput1);
        cout << inputPrompt2 <<endl;
        getline(cin,stringInput2);
    } while(isNullOrWhitespace(stringInput1)||isNullOrWhitespace(stringInput2));




    // Overloaded operators
    Rational resultAdd = b + c;
    cout << "Addition: " << resultAdd << endl;

    Rational resultSubtract = b - c;
    cout << "Subtraction: " << resultSubtract << endl;

    Rational resultMultiply = b * c;
    cout << "Multiplication: " << resultMultiply << endl;

    Rational resultDivide = b / c;
    cout << "Division: " << resultDivide << endl;

    // Overloaded comparison operators
    cout << "Greater than: " << (b > c) << endl;
    cout << "Less than: " << (b < c) << endl;
    cout << "Equal: " << (b == c) << endl;


    return 0;
}
