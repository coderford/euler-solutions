#include <iostream>
#include <vector>
using namespace std;

void multiplyBy2(vector<int> &);
int addDigits(vector<int> &);
int main() {
    // Declarations:
    vector<int> powerOf2;
    int power;
    int sum;
    // Housekeeping
    powerOf2.push_back(1);
    powerOf2.push_back(0);
    cout<<"Enter exponent: ";
    cin>>power;
    // Detail loop
    for(int i = 0; i<power; i++) {
        multiplyBy2(powerOf2);
    }

    for(int i = powerOf2.size()-1; i>=0; i--) {
        cout<<powerOf2.at(i)<<" ";
    }
    cout<<endl;
    sum = addDigits(powerOf2);
    // Finish
    cout<<"Sum = "<<sum<<endl;
    return 0;
}

void multiplyBy2(vector<int>& powerOf2) {
    //Declarations
    int carry = 0;
    int digitBy2;
    vector<int> product;
    //housekeeping
    int length = powerOf2.size();
    //detail loop
    for(int i = 0; i<length; i++) {
        digitBy2 = powerOf2.at(i)*2 + carry;
        carry = digitBy2/10;
        if(digitBy2 > 9) {
            digitBy2%=10;
        }
        product.push_back(digitBy2);

    }
    //finish
    if(product.at(product.size()-1)!=0)
        product.push_back(0);
    powerOf2 = product;
}

int addDigits(vector<int> & num) {
    int length = num.size();
    int sum = 0;
    for(int i = 0; i<length; i++) {
        sum += num.at(i);
    }
    return sum;
}


