/*

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string toString(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

bool check(int num, int denum) {
	bool isCommon = false;
	string num_str = toString(num);
	string denum_str = toString(denum);
	for(int i = 0; i<2; i++) {
		for(int j = 0; j<2; j++) {
			if(num_str.at(i)==denum_str.at(j)&&num_str.at(i)!='0') {
				num_str.erase(i, 1);		//erase(index, count)
				denum_str.erase(j, 1);
				isCommon = true;
				break;
			}
		}
		if(isCommon)
			break;
	}
	//cout<<num_str<<"--- "<<denum_str<<endl;
	if(!isCommon)
		return false;
	if ((float)(num_str.at(0)-'0')/(denum_str.at(0)-'0')== (float)num/denum)
		return true;
	return false;	
}

int main() {
	for(int i = 10; i<99; i++) {
		for(int j=i+1; j<100; j++) {
			if(check(i, j))
				cout<<i<<"/"<<j<<endl;
		}
	}	
	return 0;
}
