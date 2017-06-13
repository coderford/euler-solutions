/*

The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/
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

void store_primes(long max, vector<long> &storage) {    //store all primes below max
    long i = 2;
    while(i<max) {
        if(isPrime(i)) {
            storage.push_back(i);
        }
        i++;
    }
}


int main() {
	long max = 0;
	long sum = 0;
	int term_count = 0;
	vector<long> primes;
	store_primes(LIM, primes);	//store all the primes below 1 million
	int prime_count = primes.size();
	for(int k = 0; k<100; k++) {	//checking maximum prime sum for many beginning values for the chain
		sum = 0;
		for(int i = k; i<prime_count; i++) {	//beginning at the k+1th prime find maximum prime sum
			sum += primes.at(i);				//problem was solved with a bit of hit and trial with the value of k
			if(sum>=LIM)
				break;
			if(isPrime(sum)&&(i+1-k)>term_count) {	//i+1-k is the term count for this chain
				max = sum;
				term_count = i+1-k;
			}
		}
	}
	cout<<"MAX: "<<max<<endl;	
	cout<<"Terms: "<<term_count<<endl; 	//maximum among all the different chains constructed
}
