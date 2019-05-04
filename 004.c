/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
#include <stdio.h>

int main(){
	int i, j, x, y;
	long product, max=-1;
	for(i = 900; i<1000; i++){
		for(j = i+1; j<1000; j++ ){
			product = i*j;
			if(isPalindrome(product)&&product>max){
				max = product;
				x = i;
				y = j;
			}
		}
	}
	printf("Largest product = %ld", max);
	printf("\nFactors are %d and %d", x, y);
}

int isPalindrome(long num){
	long rev=0, temp = num;
	while(num!=0){
		rev*=10;
		rev += num%10;
		num/=10;
	}
	if(rev == temp)
	return 1;
	else return 0;
}


