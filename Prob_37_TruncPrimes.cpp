/*

The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

*/
//using brute force method... execution time is 0.9s
#include <iostream>
#include <cmath>
#define LIM 11
using namespace std;

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

long trunc_rt(long x) { //truncate a number from right
    return x/10;
}

long trunc_lt(long x) {  //truncate a number from left
    int power = log10(x);
    return x%(long)pow(10, power);
}

bool check_rt(long x) {   //check if x is truncatable from right
    while(x!=0) {
        if(!isPrime(x))
            return false;
        x = trunc_rt(x);
    }
    return true;
}

bool check_lt(long x) {     //ditto
    while(x!=0) {
        if(!isPrime(x))
            return false;
        x = trunc_lt(x);
    }
    return true;
}

int main() {
   int count = 0;
   long sum = 0;
   int tester = 11;
   while(true) {
        if(count==LIM)   //stop when LIM truncatable primes have been found
            break;
        if(check_lt(tester)&&check_rt(tester)) {
            count++;
            sum+=tester;
            cout<<tester<<" ";
        }
        tester++;
   }
   cout<<"\nSum = "<<sum<<endl;
}
