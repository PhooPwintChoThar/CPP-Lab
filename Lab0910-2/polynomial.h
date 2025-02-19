#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <algorithm>

class Polynomial {
private:
    std::vector<std::pair<int, int>> terms; // {coefficient, exponent}

    // Helper function to simplify terms (combine like terms)
    void simplify();

public:
    // Constructors
    Polynomial(); // Default constructor
    Polynomial(const std::vector<std::pair<int, int>>& terms); // Parameterized constructor

    // Destructor
    ~Polynomial();

    // Accessor and Mutator functions
    int getCoefficient(int exponent) const;
    void setCoefficient(int exponent, int newCoefficient);

    // Operator Overloading
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    Polynomial& operator=(const Polynomial& other);
    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator-=(const Polynomial& other);
    Polynomial& operator*=(const Polynomial& other);

    // Display function
    void display() const;
};

#endif
