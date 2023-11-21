//
// Created by joyce on 2023-11-15.
//

#ifndef CPPASSIGNMENT3_RATIONAL_H
#define CPPASSIGNMENT3_RATIONAL_H

#include <string>
#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

public:
    // Default constructor
    Rational();

    // Constructor for whole numbers
    Rational(int wholeNumber);

    // Two-argument constructor
    Rational(int num, int denom);

    // Constructor from string
    Rational(const string &str);

    //Destructor
    ~Rational();

    //Normalize the answers
    void normalize();

    // Function to calculate the greatest common divisor (GCD)
    int gcd(int a, int b);

    // Overloaded addition operator
    const Rational operator+(const Rational& other) const;

    // Overloaded subtraction operator
    Rational operator-(const Rational& other) const;

    // Overloaded multiplication operator
    Rational operator*(const Rational& other) const ;

    // Overloaded division operator
    Rational operator/(const Rational& other) const;

    // Overloaded greater-than operator
    bool operator>(const Rational& other) const;

    // Overloaded less-than operator
    bool operator<(const Rational& other) const;

    // Overloaded equality operator
    bool operator==(const Rational& other) const;

    friend std::ostream& operator<<(ostream& os, const Rational& rational);

};

#endif //CPPASSIGNMENT3_RATIONAL_H
