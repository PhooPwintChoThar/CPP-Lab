#include "Polynomial.h"

// Default constructor (creates an empty polynomial)
Polynomial::Polynomial() {}

// Parameterized constructor (initializes with given terms)
Polynomial::Polynomial(const std::vector<std::pair<int, int>>& inputTerms) : terms(inputTerms) {
    simplify();
}

// Destructor
Polynomial::~Polynomial() {}

// Get coefficient of a given exponent
int Polynomial::getCoefficient(int exponent) const {
    for (const auto& term : terms) {
        if (term.second == exponent) {
            return term.first;
        }
    }
    return 0; // If exponent is not found, return 0
}

// Set a new coefficient for a given exponent
void Polynomial::setCoefficient(int exponent, int newCoefficient) {
    for (auto& term : terms) {
        if (term.second == exponent) {
            term.first = newCoefficient;
            return;
        }
    }
    terms.push_back({newCoefficient, exponent});
    simplify();
}

// Operator Overloading: Addition
Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result = *this;
    result += other;
    return result;
}

// Operator Overloading: Subtraction
Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result = *this;
    result -= other;
    return result;
}

// Operator Overloading: Multiplication
Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result;
    for (const auto& term1 : terms) {
        for (const auto& term2 : other.terms) {
            result.setCoefficient(term1.second + term2.second, result.getCoefficient(term1.second + term2.second) + (term1.first * term2.first));
        }
    }
    return result;
}

// Assignment Operator
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        terms = other.terms;
    }
    return *this;
}

// Compound Assignment Operators
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    for (const auto& term : other.terms) {
        setCoefficient(term.second, getCoefficient(term.second) + term.first);
    }
    simplify();
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    for (const auto& term : other.terms) {
        setCoefficient(term.second, getCoefficient(term.second) - term.first);
    }
    simplify();
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    *this = *this * other;
    return *this;
}

// Display Polynomial
void Polynomial::display() const {
    for (size_t i = 0; i < terms.size(); ++i) {
        if (terms[i].first == 0) continue;
        if (i > 0 && terms[i].first > 0) std::cout << " + ";
        std::cout << terms[i].first;
        if (terms[i].second > 0) std::cout << "x^" << terms[i].second;
    }
    std::cout << std::endl;
}

// Helper Function: Simplify (Combine like terms and sort by exponent)
void Polynomial::simplify() {
    std::sort(terms.begin(), terms.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second; // Sort by exponent in descending order
    });

    std::vector<std::pair<int, int>> simplified;
    for (const auto& term : terms) {
        if (!simplified.empty() && simplified.back().second == term.second) {
            simplified.back().first += term.first;
        } else {
            simplified.push_back(term);
        }
    }
    terms = simplified;
}
