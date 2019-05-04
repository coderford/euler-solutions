/*
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#define LIM 2500000
using namespace std;

string toString(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

long to_num(string str) {   //converts a string to a number
    long num = 0;
    int length = str.length();
    int power = length -1;
    for(int i = 0; i<length; i++) {
        num += pow(10, power)*(str[i]-'0');
        power--;
    }
    return num;
}

bool isPrime(long n) {
    if(n<=1)
        return false;
	if(n==2)
		return true;
	for(long i = 2; i<sqrt(n)+1; i++) {
		if(n%i==0)
			return false;
	}
	return true;
}

int replace_digits(long the_num, int orig, int new_digit) {
    string str = toString(the_num);
    int len = str.length();
    for(int i = 0; i<len; i++)
        if(str.at(i)==orig+'0')
            str.at(i) = new_digit+'0';
    return to_num(str);
}

vector<int> replaced_primes_count(long x) {
    vector<int> prime_count;
    string str = toString(x);
    int counts[10] = {0};
    for(int i = 0; i<str.length(); i++)
        counts[str.at(i)-'0']++;
    for(int i = 0; i<10; i++)
        if(counts[i]>=1) {
            int count = 0;
            for(int j = 0; j<10; j++)
                if(!(str.find(i+'0')==0&&j==0))
                if(isPrime(replace_digits(x, i, j)))
                count++;
            prime_count.push_back(count);
        }
    return prime_count;
}

void print_primes_replaced(long x) {
    string str = toString(x);
    int counts[10] = {0};
    for(int i = 0; i<str.length(); i++)
        counts[str.at(i)-'0']++;
    for(int i = 0; i<10; i++)
        if(counts[i]>=1) {
            for(int j = 0; j<10; j++)
                if(isPrime(replace_digits(x, i, j)))
                    cout<<replace_digits(x, i, j)<<" ";
            cout<<endl;
        }
}
int main() {
    int req_count = 8;
    vector<long> primes;
    for(long i = 56993; i<LIM; i++)
        if(isPrime(i))
            primes.push_back(i);
    long prime_count = primes.size();

    bool found = false;
    for(int i = 0; i<prime_count; i++) {
        vector<int> temp = replaced_primes_count(primes.at(i));
        for(int j = 0; j<temp.size(); j++)
            if(temp.at(j)==req_count) {
                cout<<primes.at(i)<<endl;
                print_primes_replaced(primes.at(i));
                found = true;
                break;
            }
        if(found)
            break;
    }
    return 0;
}
