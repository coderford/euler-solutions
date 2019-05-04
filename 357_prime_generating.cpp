// 357 - Prime Generating Integers
# include <bits/stdc++.h>
# define REP(i, a, b) \
	for (int i = int(a); i <= int(b); i++)	// a to b; i is local!
# define NREP(i, a, b) \
	for (int i = int(a); i >= int(b); i--)	// decrementing loop
# define IOACCEL \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
# define CIRC_INC(i, n) \
	(i + 1) % int(n)
# define CIRC_DEC(i, n) \
	(i + int(n) - 1) % int(n)
# define ROUND(x) \
	(int)((double)int(x) + 0.5)
# define CHK cout<<"Checkpoint\n"
# define X first
# define Y second
# define INF 1000000000
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef map<string, int> msi;
typedef istringstream iss;

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

int main(int argc, char *argv[]) {
	IOACCEL;
	int LIM = 100000000;
	if(argc > 1) LIM = atoi(argv[1]);
	Sieve s(LIM);
	ll sum = 1;
	for(int i = 2; i<=LIM; i+=2) {
		bool ok = true;
		int maxd = sqrt(i);
		// you only need to check divisors upto sqrt(n)!!!
		// didn't recognize this... it makes a huge difference...
		for(int d = 1; d <= maxd; d++) {
			if(i%d == 0) 
				if(!s.isPrime(d + i/d)) {
					ok = false;
					break;
				}
		}
	}
	cout<<sum<<'\n';
}
