/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/
#include <iostream>
using namespace std;

long divSum(long num) {   //uses a smarter algorithm that also counts quotient
                            //received after every division
    if(num<=0)
        return -1;
    if(num==1)
        return 0;
    long sum = 0;
    long tester = 1;
    int lastQ = -1;   //the last quotient
    while(tester!=lastQ) {
        if(num%tester==0) {
            if(tester!=num/tester) {
                sum+=tester+num/tester;
                lastQ = num/tester;
            }
            else sum+=tester;

        }
        //cout<<num;
        tester++;
    }
    return sum-num;
}
int main() {
    long sum = 0;
    for(int i = 2; i<10000; i++) {
        int otherNum = divSum(i);
        if(i==divSum(otherNum)&&i!=otherNum) {
            cout<<i<<" "<<otherNum<<endl;
            sum+=i;
        }
    }
    cout<<endl<<"SUM: "<<sum<<endl;
    return 0;
}
