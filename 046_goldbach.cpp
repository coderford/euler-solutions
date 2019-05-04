/*

It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if(n==1)
        return false;
	if(n==2)
		return true;
	for(int i = 2; i<sqrt(n)+1; i++) {
		if(n%i==0)
			return false;
	}
	return true;
}

bool check(long x) {
    if(isPrime(x))
        return false;
    for(int i = 1; 2*i*i<x; i++) {
        if(isPrime(x-2*i*i)) {
            //cout<<i*i<<endl;
            return false;
        }
    }
    return true;
}

int main() {
    long i = 3;
    while(true) {
        if(check(i)) {
            cout<<i;
            break;
        }
        i += 2;
    }
    return 0;
}
