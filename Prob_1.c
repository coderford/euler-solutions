/*

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <stdio.h>

int main(){
	int i, n;
	long sum=0;
	printf("Find sum till what no?\n");
	scanf("%d", &n);
	for(i=1; i<n; i++){
		if(i%3==0||i%5==0)
		sum+=i;
	}
	printf("The sum is: %ld", sum);
}
