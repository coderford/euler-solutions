//had to use GMP for this problem...
//fraction is the class i created for problem 57, modified to use gmp integers
#include <iostream>
#include <gmpxx.h>
//#include <gmp.h>
using namespace std;

class fraction {
    mpz_class num;
    mpz_class denom;
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
    mpz_class get_num()
    { return num; }

    mpz_class get_denom()
    { return denom; }

    void set_num(mpz_class a)
    { num = a; }

    void set_denom(mpz_class a)
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
        mpz_class max = (num>denom)?num:denom;
        for(mpz_class i = max; i>=2; i--) {
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

long get_adder(long index) {
    if(index == 0)
        return 2;
    if((index-2)%3 == 0)
        return 2*((index-2)/3+1);
    return 1;
}

fraction convergent(int index) {
    fraction the_term(get_adder(index), 1);
    for(int i = 0; i<index; i++) {
        fraction adder(get_adder(index-i-1), 1);
        the_term = adder + the_term.reciprocal();
        //the_term.reduce();
        //cout<<i<<endl;
    }
    return the_term;
}

mpz_class sum_digits(mpz_class x) {
    mpz_class sum = 0;
    while(x!=0) {
        sum += x%10;
        x/=10;
    }
    return sum;
}

int main() {
    int term = 100;
    fraction myterm = convergent(term -1);
    //myterm.reduce();
    cout<<"Term "<<term<<": "<<endl;
    myterm.print();
    cout<<endl;
    cout<<"\nSum of digits of numerator: "<<sum_digits(myterm.get_num());
}
