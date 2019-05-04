//Improve this solution!!!
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;

string toString(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

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

void store_primes(int min, int max, vector<int> &storage) {    //store all primes between min and max
    long i = min;
    while(i<max) {
        if(isPrime(i)) {
            storage.push_back(i);
        }
        i++;
    }
}

bool is_perm(int to_check, int control) {	//checks if to_check is a perm of control
	string strA = toString(to_check);
	string strB = toString(control);
	int countA[10] = {0};
	int countB[10] = {0};
	int len;
	if((len = strA.length())!=strB.length())
		return false;
	for(int i = 0; i<len; i++) {
		countA[strA[i]-'0']++;
		countB[strB[i]-'0']++;
	}
	for(int i = 0; i<10; i++) {
		if(countA[i]!=countB[i])
			return false;
	}
	return true;
}

int main() {
	vector<int> primes;
	store_primes(1000, 10000, primes);
	int prime_count = primes.size();
	for(int i = 0; i<prime_count; i++) {
		int perm_count = 1;
		vector<int> perms;
		perms.push_back(primes.at(i));
		for(int j = i+1; j < prime_count; j++)
			if(is_perm(primes.at(j), primes.at(i))) {
				perms.push_back(primes.at(j));
				primes.erase(primes.begin()+j);
				j--;
				prime_count--;
				perm_count++;
			}
		if(perm_count>2) {
			for(int j = 0; j<perm_count; j++) {
				cout<<perms.at(j)<<" ";
			}
			cout<<endl;
			for(int j = 0; j<perm_count; j++) {
				cout<<"\t";
				for(int k = j+1; k<perm_count; k++) {
					cout<<perms.at(k)-perms.at(j)<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
