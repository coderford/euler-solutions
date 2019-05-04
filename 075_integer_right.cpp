// Brute force... should have used euler's generating formulas....
// takes 2 hrs...
#include <bits/stdc++.h>
using namespace std;

bool issqr(long a) {
	long s = sqrt(a);
	return s*s == a;
}

int main(int argc, char *argv[]) {
	long LIM = 1500000;
	if(argc > 1) LIM = atoi(argv[1]);

	map<long, long> counts;

	for(long i = 1; i <= (LIM+1)/2; i++) {
		for(long j = i+1; j<=(LIM+1)/2; j++) {
			long h2 = i*i + j*j;
			long sum = i + j + sqrt(h2);
			if(sum > LIM) break;
			if(issqr(h2)) {
				if(counts.count(sum)) counts[sum]++;
				else counts[sum] = 1;
			}
		}
	}

	int exact = 0;
	map<long, long>::iterator it = counts.begin();
	while(it != counts.end()) {
		if((*it).second == 1) exact++;
		it++;
	}
	cout<<exact<<'\n';
	return 0;
}
