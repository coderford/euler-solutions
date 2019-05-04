/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

*/
#include <vector>
#include <iostream>
using namespace std;

bool isTriplet(int x, int y, int z) {
    if(x*x == y*y + z*z)
        return true;
    if(y*y == x*x + z*z)
        return true;
    if(z*z == x*x + y*y)
        return true;
    return false;
}


int main() {
    vector<int> triplets;   //stores all the triplets with members<1000
    for(int i = 1; i<1000; i++)
        for(int j = i; j<1000; j++)
            for(int k = j; k<1000; k++) {
                if(isTriplet(i, j, k)) {
                    triplets.push_back(i);
                    triplets.push_back(j);
                    triplets.push_back(k);
                }
            }
    int triplets_length = triplets.size();
    vector<int> triplet_sums;    //stores sums of all the triplets
    for(int i = 0; i<triplets_length; i+=3) {
        int sum = triplets.at(i)+triplets.at(i+1)+triplets.at(i+2);
        triplet_sums.push_back(sum);
    }
    //after storing all the sums, we just have to find the sum with maximum frequency
    int counts[1000] = {0};
    int sum_length = triplet_sums.size();
    for(int i = 0; i<sum_length; i++) {
        counts[triplet_sums.at(i)]++;
    }
    int maxi = 0;
    int max = 0;
    for(int i = 0; i<1000; i++) {
        if(counts[i]>max) {
            max = counts[i];
            maxi = i;
        }
    }
    cout<<"Maximum solutions are for: "<<maxi<<endl;
    cout<<"No. of solutions: "<<max<<endl;
}
