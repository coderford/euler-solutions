#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Sieve {
private:
	vector<bool> hs;	// half sieve
	long lim;			// upper limit 

	void construct() {
		int h = hs.size();
		for(int i = 3;  (long) i*i < lim; i += 2) {
			if(hs[(i-3)/2])
				for(int j = (i*i-3)/2; j < h; j += (2*i-2)/2 + 1)
					hs[j] = false;
		}
	}
public:
	Sieve(long n) {
		lim = n;
		hs.assign((n+1)/2, true);
		construct();
	}

	bool isPrime(long x) {
		if(x == 0 || x == 1) return false;
		if(x == 2) return true;
		if(x%2 == 0) return false;
		return hs[(x-3)/2];
	}
};

bool isperm(int a, int b) {
	int adigs[10] = {0};
	int bdigs[10] = {0};
	while(a) {adigs[a%10]++; a /= 10;}
	while(b) {bdigs[b%10]++; b /= 10;}
	for(int i = 0; i<10; i++) if(adigs[i] != bdigs[i]) return false;
	return true;
}

int totient(int x, vector<int> &primes) {
	int p = 0;
	int ans = x;
	int save = x;
	while(primes[p] <= x && p < primes.size()) {
		if(x % primes[p] == 0) {
			ans /= primes[p];
			ans *= primes[p]-1;
			// remove ALL occurrences of prime from x:
			while(x%primes[p] == 0) x /= primes[p];
		}
		else {
			// if current prime has gone above sqrt(x)
			// remaining x must be a prime 
			if(primes[p] > sqrt(x)+1) {
				ans /= x;
				ans *= x-1;
				break;
			}
		}
		p++;
	}
	return ans;
}

void printPrimeFactors(int x, vector<int> &primes) {
	int p = 0;
	while(primes[p] <= x) {
		if(x%primes[p] == 0) {cout<<primes[p]<<' '; x /= primes[p]; }
		p++;
	}
	cout<<'\n';
}

int main() {
	Sieve s(10000000);
	vector<int> primes; primes.push_back(2);
	for(int i = 3; i<10000000; i+=2) if(s.isPrime(i)) primes.push_back(i);

	double minfrac = 100000;
	int ans = -1;

	for(int i = 3; i<10000000; i += 2) {
		if(s.isPrime(i)) continue;		// totient for primes cannot be perm
		else {
			int t = totient(i, primes);
			if(isperm(t, i) && (double) i/t < minfrac) {
				ans = i;
				minfrac = (double) i/t;
			}
		}
	}

	cout<<"ans = "<<ans<<'\n';
	cout<<"minfrac = "<<minfrac<<'\n';
	return 0;
}
