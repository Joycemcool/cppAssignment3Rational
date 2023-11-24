//Xiaoxia C++ Assignment 3 Nov.24

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include "../inc/Rational.h"

//Helper function
//Check input null or white space
bool isInteger(const string& str) {

    if(str.empty()){
        return false;
    }
    // Check if all characters in the string are whitespace
    if (std::all_of(str.begin(), str.end(), [](char c) {
        return std::isspace(static_cast<unsigned char>(c));
    })) {
        return false;
    }

    // Check if the string contains a '/' indicating a fraction
    if (str.find('/') != std::string::npos) {
        // Attempt to parse the string as a fraction in the format "numerator/denominator"
        std::istringstream iss(str);
        int numerator, denominator;
        char slash;
        iss >> numerator >> slash >> denominator;

        return (iss && slash == '/' && iss.eof());
    }

    // Create an istringstream to attempt to parse the string as an integer
    std::istringstream intStream(str);
    int value;

    // Try to parse the string as an integer
    if (intStream >> value) {
        // Successfully parsed as an integer
        // Check if there are any remaining characters (non-integer parts)
        char remaining;
        if (intStream >> remaining) {
            return false; // There are remaining characters, so it's not a complete integer
        }
        return true; // Successfully parsed as an integer
    }

    return false;
}

//Parse from String input, update Rational
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

//If input include double quote
std::string removeDoubleQuotes(const std::string& input) {
    // Create a copy of the input string
    std::string inputCopy = input;

    // Remove double quotes from the copy
    inputCopy.erase(std::remove_if(inputCopy.begin(), inputCopy.end(), [](char c) { return c == '"'; }), inputCopy.end());

    return inputCopy;
}

int main() {

    //Declare variables
    string inputPrompt1 = "Please input First Rational number, seperated by '/' if both numerator denominator provided.";
    string inputPrompt2 = "Please input Second Rational number, seperated by '/' if both numerator denominator provided.";
    string stringInput1;
    int num;
    string stringInput2;
    int denom;
    Rational Rational1;
    Rational Rational2;
    bool isValidInput1 = true;
    bool isValidInput2 = true;

    //Ask for input 1

        do {
            if(!isValidInput1){
                cout<<"Invalid input, please try again"<<endl;
            }
            isValidInput1 = true;
            cout << inputPrompt1 << endl;
            getline(cin, stringInput1);
            if (stringInput1.find('"') != string::npos ){
                if(!isInteger(removeDoubleQuotes(stringInput1))){
                    isValidInput1= false;
                };
            }
            else{
                if(!isInteger(stringInput1)){
                    isValidInput1= false;
                }
            }
        } while (!isValidInput1);

        //Ask for input 2
    do {
        if(!isValidInput2){
            cout<<"Invalid input, please try again"<<endl;
        }
        isValidInput2 = true;
        cout << inputPrompt2 << endl;
        getline(cin, stringInput2);
        if (stringInput2.find('"') != string::npos ){
            if(!isInteger(removeDoubleQuotes(stringInput2))){
                isValidInput2= false;
            };
        }
        else{
            if(!isInteger(stringInput2)){
                isValidInput2= false;
            }
        }
    } while (!isValidInput2);

    //Rational();
    if (stringInput1.find('"') != string::npos || stringInput2.find('"') != string::npos)
    {
        if (stringInput1.find('"') != string::npos){
            //Remove double quote from string
            stringInput1.erase(std::remove_if(stringInput1.begin(), stringInput1.end(), [](char c) { return c == '"'; }), stringInput1.end());
            Rational1 = Rational(stringInput1);

        } else{
            parseFromString(stringInput1,num,denom,Rational1);
        }
        if(stringInput2.find('"') != string::npos) {
            stringInput2.erase(std::remove_if(stringInput2.begin(), stringInput2.end(), [](char c) { return c == '"'; }), stringInput2.end());
            Rational2=Rational(stringInput2);
        } else{
            parseFromString(stringInput2,num,denom,Rational2);
        }
    }
    else{
        parseFromString(stringInput1,num,denom,Rational1);
        parseFromString(stringInput2,num,denom,Rational2);
    }

    cout<<"Rational1: "<<Rational1<<endl;

    cout<<"*********************************************"<<endl;
    cout<<endl;

    cout<<"Rational2: "<<Rational2<<endl;

    // Overloaded operators
    cout<<"*********************************************"<<endl;
    cout<<endl;

    Rational resultAdd = Rational1 + Rational2;
    cout << "Addition: " << resultAdd << endl;

    cout<<"*********************************************"<<endl;
    cout<<endl;

    Rational resultSubtract = Rational1 - Rational2;
    cout << "Subtraction: " << resultSubtract << endl;

    cout<<"*********************************************"<<endl;
    cout<<endl;

    Rational resultMultiply = Rational1 * Rational2;
    cout << "Multiplication: " << resultMultiply << endl;

    cout<<"*********************************************"<<endl;
    cout<<endl;

    if(!Rational2.isZero()){
        Rational resultDivide = Rational1 / Rational2;
        cout << "Division: " << resultDivide << endl;
    } else{
        cerr << "Error: Division by zero is not allowed." << endl;
    }

    // Overloaded comparison operators
    cout << "Rational 1 Greater than Rational 2 (1 - True, 0 - False): " << (Rational1 > Rational2) << endl;

    cout<<"*********************************************"<<endl;
    cout<<endl;

    cout << "Rational 1 Less than Rational 2 (1 - True, 0 - False): " << (Rational1 < Rational2) << endl;

    cout<<"*********************************************"<<endl;
    cout<<endl;

    cout << "Rational 1 Equal to Rational 2 (1 - True, 0 - False): " << (Rational1 == Rational2) << endl;

    return 0;
}
