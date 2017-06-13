/*

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/
#include <iostream>
#include <vector>
#define MAX_SUM 28123
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
    vector<int> abundants;
    bool doNotAdd[MAX_SUM] = {false};
    long sum = 0;
    int abundants_size;
    for(int i = 12; i<=MAX_SUM; i++) {
        if(divSum(i)>i)
            abundants.push_back(i);
    }
    abundants_size = abundants.size();
    /*for(int i = 0; i<abundants_size; i++) {
        cout<<abundants.at(i)<<" ";
    }*/
    for(int i = 0; i<abundants_size; i++) {
        for(int j = i; j<abundants_size; j++) {
            int currsum = abundants.at(i) + abundants.at(j);
            if(currsum <= MAX_SUM) {
                doNotAdd[currsum-1] = true;
            }
        }
    }
    for(int i = 0; i<MAX_SUM; i++) {
        if(!doNotAdd[i]) {
            sum+=i+1;
        }
    }
    cout<<sum;
    return 0;

}
