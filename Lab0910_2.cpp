#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Polynomial{
private:
    struct Term{
        int coe, expo;
    };
    vector<Term> terms;
public:
    Polynomial() {}
    Polynomial(vector<Term> t): terms(t){}
    ~ Polynomial() {}

    void setTerms(const vector<Term>& a){terms = a;}

    vector<Term> getTerms() const{return terms;}

    void setPoly(int coefficient, int exponent){
        Term newTerm;
        newTerm.coe = coefficient;
        newTerm.expo = exponent;
        terms.push_back(newTerm);
        sort(terms.begin(), terms.end(),[](const Term& a,const Term& b){return a.expo > b.expo;});

    }

    // Polynomial operator+(const Polynomial& other){
    //     Polynomial p1;
    //     vector<Term> large_term = terms;
    //     vector<Term> small_term = other.terms;
    //     if (terms.size() < other.terms.size()){
    //         large_term = other.terms;
    //         small_term = terms;
    //     }

    //     for (int i =0; i < large_term.size(); i++){
    //         for (int j =0; j < small_term.size(); j++){
    //             if (large_term[i].expo == small_term[j].expo){
    //                 large_term[i].coe += small_term[j].coe;
    //                 break;
    //             }
    //         }
    //     }
    //     p1.terms = large_term;
    //     return p1;
    // }

    Polynomial operator=(Polynomial& other){
        if (this != &other){
            terms = other.terms;
        }
        return *this;
    }

    Polynomial operator+(Polynomial& other){
        vector<Term> result = terms;
        for (const auto& term: other.terms){
            auto it = find_if(result.begin(), result.end(),[&](Term t){return t.expo == term.expo;}); //term
            if (it != result.end()){
                it-> coe += term.coe;
            }
            else{
                result.push_back(term);
            }
        }
        return Polynomial(result);
    }

    Polynomial operator*(Polynomial& other){
        vector<Term> result;
        for (int i =0; i < terms.size(); i++){
            for (int j = 0; j < other.terms.size(); j++){
                Term t1;
                t1.coe = terms[i].coe * other.terms[j].coe;
                t1.expo = terms[i].expo + other.terms[j].expo;
                result.push_back(t1);
            }
        }
        return Polynomial(result);
    }

    Polynomial operator*=(Polynomial& other){
        vector<Term> result;
        for (int i =0; i < terms.size(); i++){
            for (int j = 0; j < other.terms.size(); j++){
                Term t1;
                t1.coe = terms[i].coe * other.terms[j].coe;
                t1.expo = terms[i].expo + other.terms[j].expo;
                result.push_back(t1);
            }
        }
        terms = result;
        return *this;
    }


    friend ostream& operator<<(ostream& os,const Polynomial& poly){
        for (const auto& term: poly.terms){
            os << "+" << term.coe << "x^" << term.expo;
        }
        return os;
    }

};

int main(){
    Polynomial p1;
    p1.setPoly(2, 3);
    p1.setPoly(4, 1);

    Polynomial p2;
    p2.setPoly(3,2);
    p2.setPoly(5,0);

    Polynomial p3 = p1*p2;
    cout << p3 << endl;

    cout << (p1+p2) << endl;
    cout << (p1*=p2) << endl;
    cout << p1 << endl;


    return 0;
}