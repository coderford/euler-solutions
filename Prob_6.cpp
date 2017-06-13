/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.*/

//the first expression is just (n(n+1)(2n+1))/6 and the second is (n(n+1)/2)^2 
//subtracting the first from the second, we get n(n^2-1)(3n+2)/12
#include <iostream>
using namespace std;

int main(){
	long n, diff;
	cout<<"Enter n: ";
	cin>>n;
	diff=n*(n*n-1)*(3*n+2)/12;
	cout<<"The answer is "<<diff;
	return 0;
}

