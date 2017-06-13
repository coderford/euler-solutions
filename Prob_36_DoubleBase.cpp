/*

The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/
#include <iostream>
#include <string>
#include <sstream>
#define LIM 1000000
using namespace std;

string toString(long x) {     //converts integer to string
    ostringstream s;
    s<<x;
    return s.str();
}

string reverse(string str) {   //returns reverse of a string
    string rev=str;
    for(int i = str.length()-1; i>=0; i--) {
        rev.at(i) = str.at(str.length()-i-1);
    }
    return rev;
}

bool isPalindrome(string str) { //checks if string is a palindrome
    string rev=reverse(str);
    if(rev == str) {
        return true;
    }
    return false;
}

string toBinaryStr(long x) {    //returns binary as a string
    string rev_binary;
    while(x!=0) {
        rev_binary.append(1, x%2+'0');
        x/=2;
    }
    return reverse(rev_binary);
}

int main() {
    int sum = 0;
    for(int i = 1; i<LIM; i++) {
        if(isPalindrome(toBinaryStr(i))&&isPalindrome(toString(i))) {
            cout<<i<<" ";
            sum+=i;
        }
    }
    cout<<"\nsum = "<<sum;
}
