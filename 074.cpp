#include <bits/stdc++.h>
#define LIM 1000000 
#define LEN 60
using namespace std;

int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

long sum(long x) {
	long s = 0;
	while(x!=0) {
		s += factorial[x%10];
		x /= 10L;
	}
	return s;
}

int main() {
	int c = 0;
	vector<long> chain;
	for(long i = 1; i<LIM; i++) {
		chain.clear();
		chain.push_back(i);
		long last = i;
		long s;
		while(true) {
			s = sum(last);
			if(find(chain.begin(), chain.end(), s)!=chain.end()) {
				if(chain.size() == LEN) {
					c++;
				}
				break;
			}
			chain.push_back(s);
			last = s;
		}
	}
	cout<<c<<"\n";
	return 0;
}
