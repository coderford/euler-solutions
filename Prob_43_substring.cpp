/*The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

    d2d3d4=406 is divisible by 2
    d3d4d5=063 is divisible by 3
    d4d5d6=635 is divisible by 5
    d5d6d7=357 is divisible by 7
    d6d7d8=572 is divisible by 11
    d7d8d9=728 is divisible by 13
    d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.*/

//All the permutations of 0 to 9 are stored in p43_perms.txt..
//generated using perms.cpp
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int make_num(char i, char j, char k) {
    return 100*(i-'0')+10*(j-'0')+(k-'0');
}

long to_num(string str) {   //converts a string to a number
    long num = 0;
    int length = str.length();
    int power = length -1;
    for(int i = 0; i<length; i++) {
        num += pow(10, power)*(str[i]-'0');
        power--;
    }
    return num;
}

bool check(string str) {    //checks if a perm satisfies the property
    if(str.length()<10) {
        cout<<"String is short!"<<endl;
        return false;
    }
    if(make_num(str[7], str[8], str[9])%17==0)  //checking for 17 first as fewer
    if(make_num(str[6], str[7], str[8])%13==0)  //numbers are divisible by 17
    if(make_num(str[5], str[6], str[7])%11==0)
    if(make_num(str[4], str[5], str[6])%7==0)
    if(make_num(str[3], str[4], str[5])%5==0)
    if(make_num(str[2], str[3], str[4])%3==0)
    if(make_num(str[1], str[2], str[3])%2==0)
        return true;
    return false;
}

int main() {
    long sum = 0;
    fstream infile("p43_perms.txt");
    string str;
    infile>>str;
    while(!infile.eof()) {
        if(check(str))
            sum+=to_num(str);
        infile>>str;
    }
    cout<<"Sum = "<<sum;
    infile.close();
    return 0;
}
