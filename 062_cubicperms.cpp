/*

The cube, 41063625 (3453), can be permuted to produce two other cubes: 56623104 (3843) and 66430125 (4053). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.

*/
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

string to_string(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

bool is_perm(long to_check, long control) {	//checks if to_check is a perm of control
	string strA = to_string(to_check);
	string strB = to_string(control);
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

int count_cubicperms(long base_num) {
    long lower_lim = floor(pow(pow(10, to_string((long)pow(base_num, 3)).length()-1), 1.0/3.0));
    long upper_lim = ceil(pow(pow(10, to_string((long)pow(base_num, 3)).length()), 1.0/3.0));
    int count = 0;
    for(int i = lower_lim; i<=upper_lim; i++) {
        if(is_perm(pow(i, 3), pow(base_num, 3)))
            count++;
    }
    return count;
}

int main() {
    int i = 9, req_perms = 5;
    while(true) {
        if(count_cubicperms(i) == req_perms) {
            cout<<i<<", "<<(long)pow(i, 3)<<endl;
            break;
        }
        i++;
    }
}
