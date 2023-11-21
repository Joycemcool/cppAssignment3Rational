#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include "../inc/Rational.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Rational a;  // Default constructor
    Rational b(5);  // One Argument constructor
    Rational c(3, 4);  // Two Argument constructor
    Rational d("-1/2");  // String constructor

    // Overloaded operators
    Rational resultAdd = b + c;
    std::cout << "Addition: " << resultAdd << std::endl;

    Rational resultSubtract = b - c;
    std::cout << "Subtraction: " << resultSubtract << std::endl;

    Rational resultMultiply = b * c;
    std::cout << "Multiplication: " << resultMultiply << std::endl;

    Rational resultDivide = b / c;
    std::cout << "Division: " << resultDivide << std::endl;

    // Overloaded comparison operators
    std::cout << "Greater than: " << (b > c) << std::endl;
    std::cout << "Less than: " << (b < c) << std::endl;
    std::cout << "Equal: " << (b == c) << std::endl;


    return 0;
}
