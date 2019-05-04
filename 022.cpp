/*

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> names;
    long long sum = 0;
    string temp;
    ifstream infile("input/p22_names_modif.txt");
    infile>>temp;
    while(!infile.eof()) {          //store all names in vector
        names.push_back(temp);
        infile>>temp;
    }

    int length = names.size();
    cout<<"No. of names: "<<length<<endl;
    cout<<"Last name: "<<names.at(length-1)<<endl;
    sort(names.begin(), names.end());   //sort all the names
    for(int i = 0; i<length; i++) {     //calculate individual scores and add to total
        int alphScore = 0;
        int strLength = names.at(i).length();
        for(int j = 0; j<strLength; j++) {
            alphScore += names.at(i).at(j) - 'A' + 1;
        }
        sum += alphScore*(i+1);
        //cout<<names.at(i)<<" length = "<<strLength<<" score = "<<alphScore<<" "<<i<<endl;
    }
    cout<<"The sum of all scores is: "<<sum;
}
