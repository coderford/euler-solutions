/*

The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

bool isInt(float x) {
    if(((int)x) == x)
        return true;
    else
        return false;
}

int get_score(string word) {
    int sum = 0;
    int length = word.length();
    for(int i = 0; i<length; i++) {
        sum += word[i]-'A'+1;
    }
    return sum;
}

bool is_triangle(int num) {
    float D = 1 + 8*num;
    if(D<0){
        return false;
    }
    float a = (1 + sqrt(D))/2;
    float b = (1 - sqrt(D))/2;
    if(isInt(a)&&isInt(b)&&(b>0||a>0))
        return true;
}

int main() {
    ifstream infile("input/p42_words_modif.txt");
    string word;
    int curr_score;
    int count = 0;
    infile>>word;
    while(!infile.eof()) {
        curr_score = get_score(word);
        if(is_triangle(curr_score))
            count++;
        infile>>word;
    }
    cout<<count<<endl;
}
