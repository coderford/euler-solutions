/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#define MAX 1000        //test upto MAX
using namespace std;

int count_2s(int);    //counts power of 2 in prime factorization
int count_5s(int);    //counts power of 5 in prime factorization
double frac(int, int, int&, int&);  //returns the fractional part of a ratio
string toString(double); //returns number as string


int main() {
    int max_cycles = 0;
    int num_w_max = 2;
    for(int i = 2; i<MAX; i++) {
        int count2 = count_2s(i);
        int count5 = count_5s(i);
        int count10 = (count5>count2)?count2:count5;
        count2 -= count10;
        count5 -= count10;
        int not_in_cycle = count2 + count5 + count10;   //the number of digits
        //in fractional part that are not part of the cycle of digits
        int rec_cycles_only_m;
        int rec_cycles_only_n;
        frac(pow(10, not_in_cycle), i, rec_cycles_only_m, rec_cycles_only_n);
        //cout<<(double)rec_cycles_only_m/rec_cycles_only_n<<endl;
        int cycles_count = 1;
        int multiplied_rec_m = rec_cycles_only_m;
        int multiplied_rec_n = rec_cycles_only_n;
        int pow_10 = 1;
        while(true) {
            frac(multiplied_rec_m*10, multiplied_rec_n, multiplied_rec_m, multiplied_rec_n);
            if(toString((double)multiplied_rec_m/multiplied_rec_n)==toString((double)rec_cycles_only_m/rec_cycles_only_n))
                break;
            cycles_count++;
            pow_10++;
            if(pow_10>1000000)
                break;
            //cout<<"\t"<<(double)multiplied_rec_m/multiplied_rec_n<<endl;
        }
        if(cycles_count>max_cycles) {
            max_cycles = cycles_count;
            num_w_max = i;
        }
    }
    cout<<"Max cycles: "<<max_cycles<<endl;
    cout<<"Number with max cycles: "<<num_w_max<<endl;
    return 0;
}

int count_2s(int n) {
    int count = 0;
    while(true) {
        if(n%2 == 0) {
            n /= 2;
            count++;
        }
        else break;
    }
    return count;
}

int count_5s(int n) {
    int count = 0;
    while(true) {
        if(n%5 == 0) {
            n /= 5;
            count++;
        }
        else break;
    }
    return count;
}

double frac(int x, int y, int &m, int &n) {    //return fractional part of x/y as another ratio
    if(x<y) {
        m = x;
    }
    else m = x - y*((int)x/y);
    n = y;
}

string toString(double x) {
    ostringstream s;
    s<<x;
    return s.str();
}
