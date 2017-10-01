#include <iostream>
#include <math.h>
#include <vector>
#define LIM 1000000
using namespace std;

bool isPrime(long n) {
    if(n==1)
        return false;
	if(n==2)
		return true;
	for(long i = 2; i<sqrt(n)+1; i++) {
		if(n%i==0)
			return false;
	}
	return true;
}

void store_primes(int min, int max, vector<int> &storage) {    //store all primes between min and max
    long i = min;
    while(i<max) {
        if(isPrime(i)) {
            storage.push_back(i);
        }
        i++;
    }
}

int main() {
    vector<int> primes;
    store_primes(2, 1000, primes);
    int product, future_product = 1;
    for(int i = 0; i<primes.size()&&future_product<LIM; i++) {
        product = future_product;
        future_product *= primes.at(i);
    }
    cout<<product;
    return 0;
}
