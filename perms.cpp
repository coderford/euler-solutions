//prints all the permutations of n digits...
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

string toString(long x) {
    ostringstream s;
    s<<x;
    return s.str();
}

int print_perms(vector <int> digits,  ostream &outfile = cout, string prefix = "") {  //recursive function for printing...
    int length = digits.size();                      //prefix is for printing previous digits
    if(length == 1) {
        outfile<<prefix<<digits.at(0)<<" ";
        return 0;
    }
    for(int i = 0; i<length; i++) {
        vector<int> new_vector = digits;
        new_vector.erase(new_vector.begin()+i);
        print_perms(new_vector, outfile, toString(digits.at(i))+prefix); //the prefix has to be accumulated as the leading numbers
    }
    return 0;
}

int main() {
    //ofstream outfile("p43_perms.txt");
    vector<int> digits;
    for(int i = 1; i<=3; i++) {
        digits.push_back(i);
    }
    print_perms(digits, cout);
    cout<<endl;
    return 0;
}
