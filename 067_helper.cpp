//helper program for problem 67 - to reverse the input in file for the main program
#include <fstream>
//#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    int temp;
    ifstream infile("input/p081_data.txt");
    ofstream outfile("input/p081_backwards.txt");
    infile>>temp;
    while(!infile.eof()) {
        nums.push_back(temp);
        infile>>temp;
    }
    int length = nums.size();
    for(int i = length-1; i>=0; i--) {
        outfile<<nums.at(i)<<" ";
    }
    infile.close();
    outfile.close();
    return 0;
}
