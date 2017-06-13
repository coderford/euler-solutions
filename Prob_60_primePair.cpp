#include <iostream>
#include <math.h>
#include <vector>
#define LIM 10000
using namespace std;

long concat_int(int a, int b) { //concatenates a and b
    int b_len = ceil(log10(b));
    return pow(10, b_len)*a + b;
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

void store_primes(long max, vector<long> &storage) {    //store all primes below max
    long i = 2;
    while(i<max) {
        if(isPrime(i)) {
            storage.push_back(i);
        }
        i++;
    }
}

bool fits_set(long x, vector<int> &prime_set) {
    int set_size = prime_set.size();
    bool pass = true;
    for(int j = 0; j<set_size; j++) {
        if(!(isPrime(concat_int(x, prime_set[j]))&&isPrime(concat_int(prime_set[j], x)))) {
            pass = false;
            break;
        }
    }
   return pass;
}

int main() {
    vector<long> primes;
    store_primes(LIM, primes);
    int prime_count = primes.size();
    for(int i = 1; i<prime_count; i++) {
        vector<int> prime_set;
        prime_set.push_back(primes.at(i));
        for(int j = i+1; j<prime_count; j++) {
            if(fits_set(primes.at(j), prime_set)) {
                vector<int> prime_set2 = prime_set;
                prime_set2.push_back(primes.at(j));
                for(int k = j+1; k<prime_count; k++) {
                    if(fits_set(primes.at(k), prime_set2)) {
                        vector<int> prime_set3 = prime_set2;
                        prime_set3.push_back(primes.at(k));
                        for(int l = k+1; l<prime_count;l++) {
                            if(fits_set(primes.at(l), prime_set3)) {
                                vector<int> prime_set4 = prime_set3;
                                prime_set4.push_back(primes.at(l));
                                for(int m = l+1; m<prime_count; m++) {
                                    if(fits_set(primes.at(m), prime_set4)) {
                                        vector<int> prime_set5 = prime_set4;
                                        prime_set5.push_back(primes.at(m));
                                        int sum = 0;
                                        for(int x = 0; x<prime_set5.size(); x++)
                                            {cout<<prime_set5.at(x)<<" "; sum+=prime_set5.at(x);}
                                        cout<<"Sum: "<<sum<<endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
