/*

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long factorial (int n)				//Factorial function with loop
{
	int loops=n;
	long fact=1;
	int i;
	for (i=0;i<loops;i++)
	{
		fact*=n;
		n=n-1;
	}
	return fact;
}

int main() {
    int counter = 9;
    vector<int> digits;
    for(int i = 0; i<=9; i++)
        digits.push_back(i);
    int n;
    vector<int> nthPerm;
    cin>>n;
    while(true) {
        int remainder;
        float quotient;
        int quoCeil;
        int fact = factorial(counter);
        quotient = (float)n/fact;
        quoCeil = ceil(quotient);
        quotient = floor(quotient);
        remainder = n - fact*quotient;
        n = remainder;
        counter--;
        //cout<<quoCeil<<endl;
        nthPerm.push_back(digits.at(quoCeil-1));
        //cout<<digits.at(quoCeil-1);
        digits.erase(digits.begin() + quoCeil-1);
        if(remainder==0) {
            for(int i = digits.size()-1; i>=0; i--)
                nthPerm.push_back(digits.at(i));
            break;
        }
    }
    int length = nthPerm.size();
    cout<<"Required permutation: ";
    for(int i = 0; i<length; i++)
        cout<<nthPerm.at(i);
    return 0;
}


