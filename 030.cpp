/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 14 + 64 + 34 + 44
    8208 = 84 + 24 + 04 + 84
    9474 = 94 + 44 + 74 + 44

As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include <iostream>
#include <cmath>
using namespace std;

long sum5(long x) { //finds the sum of 5th power of digits of x
    long sum = 0;
    while(x!=0) {
        int digit = x%10;
        sum+=pow(digit, 5);
        x/=10;
    }
    return sum;
}

int main() {
    long i = 2;
    long sum = 0;
    while(i<10000000) {         //all numbers beyond 999999 will always be greater than sum of 5th_
        if(sum5(i)==i) {        //powers of their digits
            sum+=i;             //this limit is not optimal but good enough
            cout<<i<<endl;
        }
        i++;
    }
    cout<<sum<<endl;
}
