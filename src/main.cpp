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

Rational parseFromString(const string &str, int& num, int& deno,Rational& rational)
{
    //  Get the first integer
    num = atoi(&str[0]);

    // Check if there's a slash and proces the second integer if there is one
    string::size_type comma_pos = str.find('/');
    if (comma_pos != string::npos)
    {
        deno = atoi(&str[comma_pos + 1]);
        rational = Rational(num, deno);
    }
        //  No slash, min and max are the same
    else
    {
        rational = Rational(num);

    }
    return rational;
}

int main() {

    cout << "Hello, World!" << endl;
    //Declare variables
    string inputPrompt1 = "Please input first Rational number, seperated by '/' if both numerator denominator provided";
    string inputPrompt2 = "Please input second Rational number, seperated by '/' if both numerator denominator provided";
    string stringInput1;
    int num;
    string stringInput2;
    int denom;
    Rational Rational1;
    Rational Rational2;

    //Ask for input
    do{
        cout << inputPrompt1 <<endl;
        getline(cin,stringInput1);
        cout << inputPrompt2 <<endl;
        getline(cin,stringInput2);
    } while(isNullOrWhitespace(stringInput1)||isNullOrWhitespace(stringInput2));

    if (stringInput1.find('"') != string::npos || stringInput2.find('"') != string::npos)
    {
        stringInput1.erase(std::remove_if(stringInput1.begin(), stringInput1.end(), [](char c) { return c == '"'; }), stringInput1.end());
        stringInput2.erase(std::remove_if(stringInput2.begin(), stringInput2.end(), [](char c) { return c == '"'; }), stringInput2.end());

        Rational1=Rational(stringInput1);
        Rational2=Rational(stringInput2);
    } else{

        parseFromString(stringInput1,num,denom,Rational1);
        parseFromString(stringInput2,num,denom,Rational2);
    }

    cout<<Rational1<<endl;
    cout<<Rational2<<endl;


//    // Overloaded operators
    Rational resultAdd = Rational1 + Rational2;
    cout << "Addition: " << resultAdd << endl;
//
    Rational resultSubtract = Rational1 - Rational2;
    cout << "Subtraction: " << resultSubtract << endl;
//
    Rational resultMultiply = Rational1 * Rational2;
    cout << "Multiplication: " << resultMultiply << endl;
//
    Rational resultDivide = Rational1 / Rational2;
    cout << "Division: " << resultDivide << endl;
//
//    // Overloaded comparison operators
    cout << "Greater than: " << (Rational1 > Rational2) << endl;
    cout << "Less than: " << (Rational1 < Rational2) << endl;
    cout << "Equal: " << (Rational1 == Rational2) << endl;

    return 0;
}
