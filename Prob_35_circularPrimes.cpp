/*

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#define LIM 1000000
using namespace std;

string rotate_rt(string str) {	//rotates a string to the right
	int length = str.length();
	str.insert(0, 1, str.at(length-1));		//insert(index, count, chars)
	str.erase(length, 1);	//erase(index, count)
	return str;	
}
int rotate_rt(int n) {		//rotates an integer to the right
	int pow_10 = 0;
	while(pow(10, pow_10)<n) {
		pow_10++;
	}
	pow_10--;
	int last_digit = n%10;
	n = n/10;
	n += pow(10, pow_10)*last_digit;
	return n;
}

bool isPrime(int n) {
	if(n==2)
		return true;
	for(int i = 2; i<sqrt(n)+1; i++) {
		if(n%i==0)
			return false;
	}
	return true;
}
bool check(int n) {
	if(!isPrime(n))
		return false;
	int copy = n;
	n = rotate_rt(n);
	while(n!=copy) {
		if(!isPrime(n))
			return false;
		n = rotate_rt(n);
	}
	return true;
}
int main() {
	int count = 0;
	for(int i = 2; i<LIM; i++) {
		if(check(i)) {
			cout<<i<<endl;
			count++;
		}
	}
	cout<<"No of circular primes: "<<count;
	return 0;
}
