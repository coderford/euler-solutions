#include <iostream>
#include <fstream>
#include <vector>
#define LARGE_NUM 10000
using namespace std;

int main() {

    ifstream infile("input/p081_matrix.txt");
    ofstream outfile("input/p081_data.txt");
    int n, temp;
    cout<<"Enter matrix side: ";
    cin>>n;
    int **matrix = new int*[n];
    for(int i = 0; i<n; i++) {
        matrix[i] = new int[n];
    }
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            infile>>temp;
            infile.ignore();
            matrix[i][j] = temp;
        }
    }
    int rows = 2*n - 1;
    int row_num = 1;
    while(row_num<=rows) {
        int inf_count = ((row_num - n)>0)?row_num - n:0;
        for(int i = 0; i<inf_count; i++)
            outfile<<LARGE_NUM<<" ";
        int row_i = (row_num<=n)?row_num - 1:n-1;
        int row_j = (row_num<=n)?0:row_num - n;
        while(row_i>=0&&row_j<n) {
            outfile<<matrix[row_i][row_j]<<" ";
            row_i--; row_j++;
        }
        for(int i = 0; i<inf_count; i++)
            outfile<<LARGE_NUM<<" ";
        outfile<<endl;
        row_num++;
    }
    infile.close();
    outfile.close();

    vector<int> nums;   //from here on, derived from prob_67_helper
    infile.open("input/p081_data.txt");
    outfile.open("input/p081_backwards.txt");
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
}
