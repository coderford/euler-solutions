/*

It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string toString(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

bool is_perm(int to_check, int control) {	//checks if to_check is a perm of control
	string strA = toString(to_check);
	string strB = toString(control);
	int countA[10] = {0};
	int countB[10] = {0};
	int len;
	if((len = strA.length())!=strB.length())
		return false;
	for(int i = 0; i<len; i++) {
		countA[strA[i]-'0']++;
		countB[strB[i]-'0']++;
	}
	for(int i = 0; i<10; i++) {
		if(countA[i]!=countB[i])
			return false;
	}
	return true;
}

int main() {
    int i = 1;
    while(true) {
        if(is_perm(2*i, i))
        if(is_perm(3*i, i))
        if(is_perm(4*i, i))
        if(is_perm(5*i, i))
        if(is_perm(6*i, i))
            break;
        i++;
    }
    cout<<i;
}
