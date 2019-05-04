#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define LIM 100000000
using namespace std;

vector<bool> sieve;

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


void store_divisors(long num, vector<long> &storage) {   //uses a smart algorithm that also counts quotient
                                  //received after every division
    if(num<=0)
        return;
    if(num==1) {
        storage.push_back(1);
        return;
    }
    long tester = 1;
    int lastQ = -1;   //the last quotient
    while(tester!=lastQ) {
        if(num%tester==0) {
            if(tester!=num/tester) {
                storage.push_back(tester);
                storage.push_back(num/tester);
                lastQ = num/tester;
            }
            else storage.push_back(tester);

        }
        //cout<<num;
        tester++;
    }
    return;
}

bool check(long n) {
    vector<long> divs;
    store_divisors(n, divs);
    for(int i = 0; i<divs.size(); i++) {
        if(!sieve.at(divs.at(i)+n/divs.at(i)))
            return false;
    }
    return true;
}

int main() {

    prime_sieve(sieve, LIM+1);
    /*long long sum = 0;
    for(int i = 1; i<=LIM; i++)
        if(check(i))
            sum+=i;
    cout<<sum;*/
    //cout<<check(LIM);
    return 0;
}
