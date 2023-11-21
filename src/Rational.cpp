//
// Created by joyce on 2023-11-15.
//

#include <string>
#include <iostream>
#include <sstream>
#include "../inc/Rational.h"
using namespace std;

    // Function to calculate the greatest common divisor (GCD)
    int Rational:: gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Function to normalize the rational number
    void Rational :: normalize() {
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        int commonFactor = gcd(abs(numerator), denominator);
        numerator /= commonFactor;
        denominator /= commonFactor;
    }

    // Default constructor
    Rational :: Rational() :numerator(0), denominator(1) {
        cout << "Default constructor called." << endl;
    }

    // Constructor for whole numbers
    Rational ::Rational(int wholeNumber) : numerator(wholeNumber), denominator(1) {
        cout << "One Argument constructor called." << endl;
    }

    // Two-argument constructor
    Rational ::Rational(int num, int denom) : numerator(num), denominator(denom) {
        std::cout << "Two Argument constructor called." << std::endl;
        normalize();
    }

    // Constructor from string
    Rational :: Rational(const string &str) {
        cout << "String constructor called." << endl;
        stringstream ss(str);
        char slash;
        ss >> numerator;
        if (ss >> slash) {
            ss >> denominator;
        } else {
            denominator = 1;
        }
        normalize();
    }

    //Destructor
    Rational ::~Rational(){
        cout<<"Need a destructor here?"<<endl;
    }

    // Overloaded addition operator
    const Rational Rational :: operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    // Overloaded subtraction operator
    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    // Overloaded multiplication operator
    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    // Overloaded division operator
    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            return Rational();  // Returning default value in case of division by zero
        }
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    // Overloaded greater-than operator
    bool operator>(const Rational& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    // Overloaded less-than operator
    bool operator<(const Rational& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    // Overloaded equality operator
    bool operator==(const Rational& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& rational) {
        os << rational.numerator;
        if (rational.denominator != 1) {
            os << '/' << rational.denominator;
        }
        return os;
    }

};
