#include <iostream>
#include <vector>
#define LIM 1000000000
using namespace std;

void prime_sieve(vector<bool> &sieve, long last_num) {	//creates a sieve upto last_num
	sieve.push_back(false);
	sieve.push_back(false);
	for(long i = 2; i<=last_num; i++) {
		sieve.push_back(true);
	}
	long sieve_size = last_num + 1;
	for(long i = 2; i<sieve_size; i++)
		if(sieve.at(i)) {
			for(long j = 2*i; j<sieve_size; j+=i) {
				sieve.at(j) = false;
			}
		}
}

int main(int argc, char *argv[]) {
    vector<bool> sieve;
    prime_sieve(sieve, LIM);    //create prime sieve
    long side_len = 3;
    long prime_count = 0;
    long s1_diff = -6;
    long s2_diff = -4;
    long s3_diff = -2;
    while(true) {
        //if(side_len == 9) break;
        long sqr = side_len*side_len;
        long s1 = sqr + s1_diff;
        long s2 = sqr + s2_diff;
        long s3 = sqr + s3_diff;
        if(sieve.at(s1))
            prime_count++;
        if(sieve.at(s2))
            prime_count++;
        if(sieve.at(s3))
            prime_count++;
        double prime_percent = 100.0*prime_count/(side_len*2-1);
        cout<<"Side = "<<side_len<<" "<<prime_percent<<"%"<<" "<<prime_count<<endl;
        if(prime_percent<10)
            break;
        s1_diff -= 6;
        s2_diff -= 4;
        s3_diff -= 2;
        side_len += 2;
    }
    cout<<side_len;
    return 0;
}
