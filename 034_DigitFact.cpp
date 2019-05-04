/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/
#include <iostream>
#include <string>
#include <sstream>
#define LIM 3000000
using namespace std;

string toString(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}
int factorials[] = { 1,  1,  2,  6,  24,  120,  720,  5040,  40320,  362880 }; 
bool check(int n) {
	string str = toString(n);
	int sum = 0;
	int length = str.length();
	for(int i = 0; i<length; i++) {
		sum+=factorials[str.at(i)-'0'];
	}
	if(sum==n) 
		return true;
	return false;
}
int main() {
	int sum = 0;
	for(int i=10; i<LIM; i++) {
		if(check(i)) {
			cout<<i<<" ";
			sum+=i;
		}
	}
	cout<<"\nsum = "<<sum<<endl;
	return 0;
}
