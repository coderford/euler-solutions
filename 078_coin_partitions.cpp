// Problem: find least n for which p(n) is divisible by 1,000,000
// where p(n) is the partition function

// This solution uses euler's recurrence relation for partitions
// algorithm from http://www.numbertheory.org/php/partition.html
// runs in 0.25 seconds

// for MOD = 10,000,000, runs in 2m 48sec 

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

int parity(int m) {
	if(m%2) return -1;
	else return 1;
}

int main() {
	int LIM = 1000000;
	int MOD = 1000000;

	int m = LIM;
	vi p(m + 1);
	int s, j, k, t, kk;
	p[0] = 1;
	
	for(int i = 1; i<=m ;i++) {
		j = 1; k = 1; s = 0;	
		while(j > 0) {
			kk = k*k;
			t = parity(k);

			j = i - (3*kk + k)/2;
			if(j >= 0) s = (s - t*p[j])%MOD;

			j = i - (3*kk - k)/2;
			if(j >= 0) s = (s - t*p[j])%MOD;
			k++;
		}
		p[i] = s%MOD;
		if(p[i] == 0) {
			cout<<i<<'\n';
			break;
		}
	}
	return 0;
}
