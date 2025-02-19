#include "Polynomial.h"

int main() {
    Polynomial p1({{3, 2}, {2, 1}, {1, 0}});
    Polynomial p2({{1, 1}, {4, 0}});

    std::cout << "Polynomial 1: ";
    p1.display();

    std::cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = p1 + p2;
    std::cout << "Sum: ";
    sum.display();

    Polynomial diff = p1 - p2;
    std::cout << "Difference: ";
    diff.display();

    Polynomial prod = p1 * p2;
    std::cout << "Product: ";
    prod.display();

    return 0;
}
