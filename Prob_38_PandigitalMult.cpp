/*

Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

*/
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

string toString(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

int get_length(long x) {
    return 1 + (int) log10(x);
}

long concat_nums(long x, long y) {
    return pow(10, get_length(y))*x + y;
}

long get_9_mult(long x) {
    long the_product = 0;
    int length = 0;
    int multiplier = 1;
    while(length<9) {
        the_product = concat_nums(the_product, multiplier*x);
        multiplier++;
        length = get_length(the_product);

    }
    if(length == 9)
        return the_product;
    return 0;
}

bool is_pandigital(long x) {
    int digit_counts[10] = {0};
    string the_string = toString(x);
    for(int i = 0; i<the_string.length(); i++)
        digit_counts[the_string.at(i)-'0']++;
    for(int i = 1; i<10; i++)
        if(digit_counts[i]==0)
            return false;
    return true;
}

int main() {
    long max = 0;
    int maxi = -1;
    for (int i = 1; i<10000; i++) {
        long consec_multiple = get_9_mult(i);
        if(consec_multiple>max&&is_pandigital(consec_multiple)) {
            max = consec_multiple;
            maxi = i;
        }
    }
    cout<<"MAX = "<<max<<endl;
    cout<<"for i = "<<maxi<<endl;
}
