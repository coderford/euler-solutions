//does not solve the problem... but contains some useful functions...
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

string to_string(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

long long fact(int x) {
    long long pro = 1;
    for(int i = 1; i<=x; i++)
        pro*=i;
    return pro;
}
long long to_int(string str) {
    int len = str.length();
    int the_pow = 0;
    long long the_num = 0;
    for(int i = len-1; i>=0; i--) {
        the_num += pow(10, the_pow)*(str.at(i)-'0');
        the_pow++;
    }
    return the_num;
}

bool is_cube(long long x) {
    if (pow(round(pow(x, 1.0/3.0)), 3) == x)
        return true;
    return false;
}

int store_perms(vector<long long> &storage, vector <char> digits, string prefix = "") {
    int length = digits.size();                      //prefix is for printing previous digits
    if(length == 1) {
        storage.push_back(to_int(prefix+digits.at(0)));
        return 0;
    }
    for(int i = 0; i<length; i++) {
        vector<char> new_vector = digits;
        new_vector.erase(new_vector.begin()+i);
        store_perms(storage, new_vector, digits.at(i)+prefix); //the prefix has to be accumulated as the leading numbers
    }
    return 0;
}

void decompose(long long x, vector<char> &storage) {
    storage.clear();
    string str = to_string(x);
    for(int i = 0; i<str.length(); i++)
        storage.push_back(str.at(i));
}

int count_cubicperms(long long num) {
    int count = 0;
    vector<long long> perms;
    vector<char> digits;
    decompose(num, digits);
    store_perms(perms, digits);
    int perm_count = perms.size();
    for(int i = 0; i<perm_count; i++)
        if(is_cube(perms.at(i)))
        count++;
    int digit_n[10] = {0};
    string str = to_string(num);
    for(int i = 0; i<str.length(); i++)
        digit_n[str.at(i)-'0']++;
    for(int i = 0; i<10; i++)
        if(digit_n[i]>0)
        count/=fact(digit_n[i]);
    return count;
}

int main() {
    int req_perms = 5;
    long i = 500;
    int count = 0;
    while(true) {
        if((count=count_cubicperms(pow(i, 3)))>=req_perms) {
            cout<<i<<", "<<(long)pow(i, 3)<<" count: "<<count<<endl;
            //break;
        }
        //cout<<"i = "<<i<<", pow = "<<(long long)pow(i, 3)<<" count: "<<count<<endl;
        i++;
    }
    //cout<<count_cubicperms(pow(405, 3));
}
