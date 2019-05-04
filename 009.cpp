/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
#include <math.h>
using namespace std;

bool isInt(float);
int main() {
    float a, b, c;
    float SUM = 1000;
    float aPlusb, aIntob;
    float D;
    bool found = false;
	for(c = SUM/4; c<SUM; c++) {
		aPlusb = SUM - c;
		aIntob = SUM*SUM/2 - SUM*c; //this expression can be obtained by squaring the eq
									//c = SUM -(a+b) and then simplifying
		//cout<<"a+b = "<<aPlusb<<endl;
		//cout<<"a*b = "<<aIntob<<endl;
		D = aPlusb*aPlusb - 4*aIntob;
		if(D<0){
			continue;
		}
		a = (aPlusb + sqrt(D))/2;
		b = (aPlusb - sqrt(D))/2;
		if(isInt(a)&&isInt(b)&&a>0&&b>0) {
			found = true;
			break;
		}
	}
	if(found) {
		cout<<"a = "<<a<<" b = "<<b<<" and c = "<<c<<endl;
	}
	else {
		cout<<"NOT FOUND!"<<endl;
	}
    return 0;
}

bool isInt(float x) {
    if(((int)x) == x)
        return true;
    else
        return false;
}
