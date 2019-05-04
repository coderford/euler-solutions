#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    infile data("input/p081_data.txt");
    int n, rows;
    cout<<"Enter size of matrix: ";
    cin>>n;
    rows = 2*n - 1;
    int rowsize = 2;
    int row_inc = 1;
    vector<int> prev_row;
    vector<int> curr_row;
    int temp;
    int counter = 2;
    infile>>temp;
    prev_row.push_back(temp);
    while(counter<=rows) {
        curr_row.clear();
        for(int i = 0; i<rowsize; i++) {
            infile>>temp;
            curr_row.push_back(temp);
        }



        rowsize += row_inc;
        if(rowsize == n)
            row_inc = -1;
        prev_row = curr_row;
    }

}

