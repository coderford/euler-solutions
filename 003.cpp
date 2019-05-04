/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

//Bruteforcing my way through :)
#include <iostream>
#include <math.h>
using namespace std;

int isPrime(double num);
int main(){
	double num;
	double i, sol;
	
	cout<<"Enter number: ";
	cin>>num;
	double sqt = sqrt(num);
	for(i=1; i<sqt; i++){
		if(fmod(num, i)==0)
		if(isPrime(i))
		sol = i;
	}
	if(sol == 1)
	cout<<"Largest prime factor is "<<num;
	else
	cout<<"Largest prime factor is "<<sol;
}

int isPrime(double num){
	double i;
	double sqt = sqrt(num);
	for(i = 2; i<sqt; i++){
		if(fmod(num, i)==0)
		return 0;
	}
	return 1;
}
