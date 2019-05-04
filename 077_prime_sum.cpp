// What is the first number that can be expressed as a sum of 2 or more 
// primes in atleast 5000 different ways?
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
	int LIM = 1000;
	if(argc > 1) LIM = atoi(argv[1]);
	Sieve s(LIM);
	vi primes;
	REP(i, 2, LIM) if(s.isPrime(i)) primes.push_back(i);

	// initialize dp table:
	// dp[i][j] = ways to make i using primes upto index j
	vvi ways(LIM + 1, vi(primes.size(), 0));
	REP(i, 0, primes.size()-1)
		ways[0][i] = 1;		// no. of ways to make 0 is always 1

	// fill out dp table:
	REP(maxp, 0, primes.size()-1) {
		REP(i, 1, LIM) {
			// copy over previous vals:
			if(maxp > 0) ways[i][maxp] = ways[i][maxp-1];
			
			// add number of ways after subtracting current prime
			if(primes[maxp] <= i)
				ways[i][maxp] += ways[i-primes[maxp]][maxp];
		}
	}

	// find out required no. of ways
	int save;
	REP(i, 4, LIM) {
		if(ways[i][primes.size()-1] > 5000) {
			save = i;
			break;
		}
	}

	// print results:
	REP(i, 2, save) 
		cout<<i<<' '<<ways[i][primes.size()-1]<<'\n';
	return 0;
}
