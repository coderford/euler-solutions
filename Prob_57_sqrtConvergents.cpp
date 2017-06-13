#include <iostream>
using namespace std;

class fraction {
    long num;
    long denom;
    public:
    fraction() {
        num = 1;
        denom = 1;
    }
    fraction(long a, long b) {
        num = a;
        denom = b;
    }
    void print() {
        cout<<num<<"/"<<denom;
    }
    long get_num()
    { return num; }

    long get_denom()
    { return denom; }

    void set_num(long a)
    { num = a; }

    void set_denom(long a)
    { denom = a; }

    fraction operator +(fraction b) {
        fraction sum;
        sum.set_denom(denom*b.get_denom());
        sum.set_num(num*b.get_denom()+denom*b.get_num());
        //sum.reduce();
        return sum;
    }

    fraction operator *(fraction b) {
        fraction product;
        product.set_num(num*b.get_num());
        product.set_denom(denom*b.get_denom());
        //product.reduce();
        return product;
    }

    fraction reciprocal() {
        fraction reci;
        reci.set_num(denom);
        reci.set_denom(num);
        return reci;
    }

    fraction operator /(fraction b) {
        return *this*b.reciprocal();
    }

    fraction reduce() {
        long &max = (num>denom)?num:denom;
        for(int i = max; i>=2; i--) {
            if(num%i==0 && denom%i==0) {
                num /= i;
                denom /= i;
            }
        }
        return *this;
    }

    fraction inverse() {
        fraction inv = *this;
        inv.set_num(-num);
        return inv;
    }
};

void sqrt_2(int iterations) {
    fraction last_term(5,2);
    fraction TWO (2, 1);
    fraction ONE(1, 1);
    for(int i = 0; i<iterations-1; i++) {
        last_term = TWO + (ONE / last_term);
    }
    last_term = last_term + ONE.inverse();
    last_term.print();
}

int main() {
    for(int i = 1; i<=100; i++) {
        sqrt_2(i);
        cout<<"  ";
    }
}
