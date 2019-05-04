#include <iostream>
#include <vector>
using namespace std;

int main() {
    bool isPrime = true;
    unsigned long long sum = 0;
    vector<int> primes;
    int toCheck = 2;
    int innerCounter = 0;
    int primeCount;
    long checkLimit;
    cout<<"Enter upper limit for adding primes: ";
    cin>>checkLimit;
    while(toCheck<checkLimit) {
        primeCount = primes.size();
        while(innerCounter<primeCount) {
            if(toCheck%primes.at(innerCounter) == 0) {
                isPrime = false;
                break;
            }
            innerCounter++;
        }
        innerCounter = 0;
        if(isPrime) {
            cout<<toCheck<<endl;
            sum+=toCheck;
            primes.push_back(toCheck);
        }
        toCheck++;
        isPrime = true;
    }
    cout<<"Sum of primes upto "<<checkLimit<<" is "<<sum;
}
