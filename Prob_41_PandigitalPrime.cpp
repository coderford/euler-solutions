/*

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/
/*
    ->for any 8 digit pandigital, sum of digits = 1+2+3+4+5+6+7+8 = 36
    and for 9 digit pandigitals, sum = 36+9 = 45
    ->this means that all 8 digit and 9 digit pandigitals have 3 as a factor
    so there is no need to find 8 or 9 digit pandigital primes, they don't exist
    PS: I didn't realize this and at first just entered the largest 7 digit
        pandigital prime.. it turned out to be correct. Otherwise, i would have
        gone on to check 8 digit and 9 digit pandigitals..
*/
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

string toString(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

bool is_pandigital(long x,int lim) {
    int digit_counts[10] = {0};
    string the_string = toString(x);
    for(int i = 0; i<the_string.length(); i++)
        digit_counts[the_string.at(i)-'0']++;
    for(int i = 1; i<lim+1; i++)
        if(digit_counts[i]==0)
            return false;
    return true;
}

bool isPrime(long x) {
    if(x==1)
        return false;
    if(x==2)
        return true;
    for(int i = 2; i<sqrt(x)+1; i++) {
        if(x%i==0)
            return false;
    }
    return true;
}

int get_length(long x) {
    return 1 + (int) log10(x);
}

int main() {
    long max = 0;
    for(long i = 7654321; i>=1234567; i-=2) {   //checking for 7 digit pandigital primes..
        //cout<<i;
        if(is_pandigital(i, get_length(i))&&isPrime(i)) {
            max = i;
            break;
        }
        //cout<<endl;
    }
    cout<<max<<endl;
    return 0;
}
