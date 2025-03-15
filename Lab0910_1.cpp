#include<iostream>
using namespace std;

class Fraction{
private:
    int upper, lower;
public:
    Fraction(int up = 1, int low = 1) : upper(up), lower(low){
        if (lower == 0) {
            cout << "The lower part can't be zero.\n";
            return;
        }
        simplify();
    }

    int findGcd(int upper, int lower){
        int least_val = upper;
        if (upper > lower){
            least_val = lower;
        }
        int gcd = 1;
        for (int i = 1; i <= least_val; i++){
            if(upper%i == 0 && lower%i ==0) {
                gcd = i;
            }
        }
        return gcd;
    }

    void simplify(){
        int gcd = findGcd(upper, lower);
        lower = lower/gcd;
        upper = upper/gcd;
    }

    bool operator>(const Fraction& other) {
        return upper*other.lower > lower*other.upper;
    }

    bool operator<(const Fraction& other){
        return upper*other.lower < lower*other.upper;
    }

    bool operator ==(const Fraction& other){
        return upper*other.lower == lower*other.upper;
    }

    Fraction operator+(Fraction& other)  {
        upper = upper*other.lower + other.upper*lower;
        lower = lower*other.lower;
        return Fraction(upper, lower);
    }

    Fraction operator-(Fraction& other){
        upper = upper*other.lower - other.upper*lower;
        lower = lower*other.lower;
        return Fraction(upper, lower);
    }

    Fraction operator*(Fraction& other){
        upper = upper * other.upper;
        lower = lower * other.lower;
        return Fraction(upper, lower);
    }

    Fraction operator/(Fraction& other){
        upper = upper * other.lower;
        lower = lower * other.upper;
        return Fraction(upper, lower);
    }

    friend istream& operator>>(istream& in, Fraction& Self){
        char slesh;
        if (!(in >> Self.upper >> slesh >> Self.lower) || slesh != '/' || Self.lower == 0){
                in.setstate(ios::failbit);
        }
        return in;
    }


    friend ostream& operator<<(ostream& os, const Fraction& obj) {
        os << obj.upper << "/" << obj.lower << endl;
        return os;
    }
};

int main() {
    Fraction f1;
    Fraction f2;
    cout << "Enter first Fraction: ";
    cin >> f1;
    cout << "Enter second fraction: ";
    cin >> f2;
    cout <<  (f1 /f2) << endl;

    if (f1 > f2) cout << "f1 is greater than f2\n";
    if (f1 < f2) cout << "f1 is less than f2\n";

    return 0;

    
}
