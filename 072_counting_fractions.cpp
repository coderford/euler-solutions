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

int totient(int x, vector<int> &primes, Sieve &s) {
	if(s.isPrime(x)) return x-1;
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

int main(int argc, char *argv[]) {
	int LIM = 1000000;
	if(argc > 1) 
		LIM = atoi(argv[1]);
	Sieve s(LIM);
	vector<int> primes; primes.push_back(2);
	for(int i = 3; i<=LIM; i+=2) if(s.isPrime(i)) primes.push_back(i);

	long ans = 0;
	for(int i = 2; i<=LIM; i++) {
		ans += totient(i, primes, s);
	}

	cout<<ans<<'\n';
	return 0;
}
