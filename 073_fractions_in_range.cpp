
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(int argc, char *argv[]) {
	int LIM = 12000;
	if(argc > 1) LIM = atoi(argv[1]);

	int count = 0;
	for(int i = 3; i <= LIM; i++) {
		for(int j = i/3 + 1; (float)j/i < 0.5; j++) {
			if(gcd(j, i) == 1) count++;
		}
	}
	cout<<count<<'\n';
	return 0;
}
