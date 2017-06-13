/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

string toString(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

bool is_pandigital(long multiplicand, long multiplier, long product) {
	int digit_counts[10] = {0};
	string m1_str = toString(multiplicand);
	string m2_str = toString(multiplier);
	string p_str = toString(product);
	for(int i = 0; i<m1_str.length(); i++) {
		digit_counts[m1_str[i]-'0']++;
	}
	for(int i = 0; i<m2_str.length(); i++) {
		digit_counts[m2_str[i]-'0']++;
	}
	for(int i = 0; i<p_str.length(); i++) {
		digit_counts[p_str[i]-'0']++;
	}
	for(int i = 1; i<10; i++) {
		if(digit_counts[i]!=1)
			return false;
	}
	if(digit_counts[0]!=0)
		return false;
	return true;
}
int main() {
	vector<int> products;
	for(long i = 1; i<100; i++)
		for(long j = 1; j<4000; j++) {
			if(is_pandigital(i, j, i*j)) {
				products.push_back(i*j);
				//cout<<"i = "<<i<<" j = "<<j<<" product = "<<i*j<<endl;
			}
		}
	sort(products.begin(), products.end());
	products.erase(unique(products.begin(), products.end()), products.end());
	long sum = 0;
	int length = products.size();
	for(int i = 0; i<length; i++) 
		sum+=products.at(i);
	cout<<sum<<endl;
	return 0;
}



