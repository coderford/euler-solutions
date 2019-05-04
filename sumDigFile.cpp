#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("input/factorial_100.txt");
    char ch;
    int sum = 0;
    infile>>ch;
    while(!infile.eof()) {
	sum += ch - '0';
	infile>>ch;
    }
    infile.close();
    cout<<sum;
    return 0;
}
