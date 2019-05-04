/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?
*/
#include <iostream>
using namespace std;

int main() {			//checking all the possibilities...
	long count = 0;
	for(int i = 0; i<=200; i++)		//1p
		for(int j = 0; j<=100; j++)			//2p
				for(int l = 0; l<=40; l++)		//5p
					for(int m = 0; m<=20; m++)		//10p
						for(int n = 0; n<=10; n++)		//20p
							for(int o = 0; o<=4; o++)		//50p
								for(int p = 0; p<=2; p++)		//100p
									{	
										int sum = i*1+j*2+l*5+m*10+n*20+o*50+p*100;
										if (sum == 200)
											count++;
									}
	cout<<count+1;		//+1 is for 2 pound coin..					
}
