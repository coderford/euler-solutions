#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("p081_backwards.txt"); //run prob_81_helper with p081_matrix.txt to get this file first
    vector<int> arrAbove;
    vector<int> sumArr;
    int rows;
    int temp;
    cout<<"Enter number of rows: ";
    cin>>rows;
    for(int i=0; i<rows; i++) {
        infile>>temp;
        sumArr.push_back(temp);
    }
    for(int i=rows-1; i>0; i--) {
        for(int j = 0; j<i; j++) {
            infile>>temp;
            arrAbove.push_back(temp);
        }
        for(int j = 0; j<i; j++) {
            arrAbove.at(j) += (sumArr.at(j)<sumArr.at(j+1))?sumArr.at(j):sumArr.at(j+1);
        }
        sumArr = arrAbove;
        arrAbove.clear();
    }
    cout<<"The minimum sum is: "<<sumArr.at(0);
    infile.close();
    return 0;
}
