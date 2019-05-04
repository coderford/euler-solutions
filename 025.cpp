/*

The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/
#include <iostream>
#include <string>
using namespace std;

class num {
    string value;
public:
    num(string s) {
        value = s;
    }
    num() {
        ;
    }
    string returnString() {
        return value;
    }
    void add(num &toAdd);
    void set(string s) {
    	value = s;
	}
    void get() {
        cin>>value;
    }
    void put() {
        cout<<value;
    }
    friend num add(num &, num &);
};

num add(num &num1, num &num2) {
	num sum = num1;
    string addStr = num2.value;
    int lengthToAdd=addStr.length();
    int mylength = sum.value.length();
    int equal_length;
    if(mylength<lengthToAdd) {
        sum.value.insert(0, lengthToAdd-mylength,'0' );
    }
    else if(lengthToAdd<mylength) {
        addStr.insert(0, mylength-lengthToAdd, '0');
    }
    equal_length = sum.value.length();
    int carry = 0;
    for(int i=equal_length-1; i>=0; i--) {
        int sumDig = sum.value.at(i)-'0'+addStr.at(i)-'0' + carry;
        if(sumDig>9) {
            carry = sumDig/10;
            sumDig %= 10;
        }
        else carry = 0;
        sum.value.at(i) = sumDig + '0';
    }
    if(carry != 0) {
        sum.value.insert(0, 1, carry+'0');
    }
    return sum;
}

int main() {
	num fn, fn1("1"), fn2("1");
	int currIndex = 3;
	int requiredLength = 1000;
	//cin>>requiredLength;
	fn = add(fn1, fn2);
	while(true) {
		if(fn.returnString().length() >= requiredLength) {
			break;
		}
		num temp = fn1;
		fn1 = fn;
		fn2 = temp;
		fn = add(fn1, fn2);
		currIndex++;
	}
	cout<<"i = "<<currIndex<<endl;
	cout<<"fn = "<<fn.returnString()<<endl;
	cout<<"length = "<<fn.returnString().length()<<endl;
	return 0;
}
