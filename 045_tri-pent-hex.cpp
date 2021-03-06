/*

Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
Triangle 	  	Tn=n(n+1)/2 	  	1, 3, 6, 10, 15, ...
Pentagonal 	  	Pn=n(3n−1)/2 	  	1, 5, 12, 22, 35, ...
Hexagonal 	  	Hn=n(2n−1) 	  	1, 6, 15, 28, 45, ...

It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.
*/

#include <iostream>
#include <cmath>
using namespace std;

bool isInt(double x) {
    if(((int)x) == x)
        return true;
    else
        return false;
}

bool is_pent(long x) {
    double D = 24*x+1;  //double is necessary as float is not precise enough...
    double sol = (sqrt(D)+1)/6; //i got a close but wrong answer because of float
    if(isInt(sol)) {
        //cout<<"pent: "<<sol<<endl;
        return true;
    }
    return false;
}

bool is_hex(long x) {
    double D = 8*x + 1;    //simply solving the eq for +ve value of n;
    double sol = (sqrt(D)+1)/4;
    if(isInt(sol)) {
        //cout<<"hex: "<<sol<<endl;
        return true;
    }
    return false;
}

long triangle(long n) {
    return n*(n+1)/2;
}

int main() {    //simple brute force
    long i = 286;
    while(true) {
        if(is_pent(triangle(i))&&is_hex(triangle(i)))
            break;
        i++;
    }
    cout<<"i = "<<i<<endl;
    cout<<"t = "<<triangle(i);
    return 0;
}
