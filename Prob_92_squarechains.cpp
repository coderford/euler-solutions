/*

A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?


*/
//not very well optimized... but under the 1 minute rule!

#include <iostream>
#include <vector>
#define LIM 10000000
using namespace std;

long square(int x) {
    return x*x;
}
long sum_dig_squares(int x) {
    long the_sum = 0;
    while(x!=0) {
        the_sum += square(x%10);
        x/=10;
    }
    return the_sum;
}

int main() {
    vector<bool> ends_89;
    int count = 0;
    for(int i = 0; i<LIM + 1; i++)
        ends_89.push_back(false);
    for(int i = LIM-1; i>0; i--) {
        if(!ends_89.at(i)) {
            vector<int> intermediates;
            int previous = i;
            while(true) {
                int sqsum = sum_dig_squares(previous);
                if(sqsum == 89) {
                    count++;
                    for(int j = 0; j<intermediates.size(); j++)
                        ends_89.at(intermediates.at(j)) = true;
                    //ends_89.at(previous) = true;
                    break;
                }
                else if(sqsum == 1) {
                    break;
                }
                else {
                    previous = sqsum;
                    intermediates.push_back(sqsum);
                }
            }
        }
        else count++;
    }
    cout<<count;
}
