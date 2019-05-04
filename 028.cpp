/*

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/
#include<iostream>
#define SIZE 1001   //the number of rows/columns in the spiral
using namespace std;

long diag_sum(int start, int diff, int terms) {
    long sum = 0;
    for(int i = 0; i<terms; i++) {
        sum += start;
        start+=diff;
        diff+=8;
    }
    return sum;
}
int main() {
    long sum = 0;
    //the number of terms along a diagonal is (SIZE+1)/2 (assuming odd SIZE); then -1 for the middle 1
    sum += diag_sum(3, 10, (SIZE+1)/2-1); //the diagonals form an easily summable series
    sum += diag_sum(5, 12, (SIZE+1)/2-1); //so summing across the four directions
    sum += diag_sum(7, 14, (SIZE+1)/2-1);
    sum += diag_sum(9, 16, (SIZE+1)/2-1);
    sum += 1;                             //and adding the middle 1 in the end
    cout<<"Sum along diagonals: "<<sum<<endl;
    return 0;
}
