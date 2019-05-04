#include <iostream>
#include <math.h>
#include <vector>
#define LIM 20000000
using namespace std;

void prime_sieve(vector<bool> &sieve, long last_num) {	//creates a sieve upto last_num
	sieve.push_back(false);
	sieve.push_back(false);
	for(int i = 2; i<=last_num; i++) {
		sieve.push_back(true);
	}
	long sieve_size = last_num + 1;
	for(int i = 2; i<sieve_size; i++)
		if(sieve.at(i)) {
			for(int j = 2*i; j<sieve_size; j+=i) {
				sieve.at(j) = false;
			}
		}
}

long factors_sum(long x, vector<long> &primes, vector<bool> &sieve) {	//finds sum of terms in prime factorisation
	long sum = 0;
	long prime_count = primes.size();
	long i = 0;
	while(x != 1) {
		if(sieve.at(x)) {
			sum += x;
			break;
		}
		if(x%primes.at(i) == 0) {
			sum += primes.at(i);
			x /= primes.at(i);
		}
		else i++;
	}
	return sum;
}

vector<bool> sieve;
vector<long> primes;
unsigned long long bin_prime_sum(long n, long r) {
	r = ((n-r)<r)?n-r:r;
	//unsigned long long total_sum = 0;
	unsigned long long sum1 = 0;
	for(long i = n-r+1; i<=n; i++) {
		sum1 += factors_sum(i, primes, sieve);
	}
	unsigned long long sum2 = 0;
	for(long i = 2; i<=r; i++) {
		sum2 += factors_sum(i, primes, sieve);
	}
	return sum1-sum2;
}

int main() {
	prime_sieve(sieve, LIM);
	for(int i = 2; i<=LIM; i++) {
		if(sieve.at(i))
		primes.push_back(i);
	}
	cout<<"The diff is: "<<bin_prime_sum(20000000, 15000000);
}
