/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

*/
#include <iostream>
#include <string>
#define MAX_NUM 1000
using namespace std;

string toWords(int number) {    //lazy solution... using this function from another program to build the strings
                                //and then count the number of letters;
    switch(number) {
        case 0: return "";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        case 20: return "twenty";
        case 30: return "thirty";
        case 40: return "forty";
        case 50: return "fifty";
        case 60: return "sixty";
        case 70: return "seventy";
        case 80: return "eighty";
        case 90: return "ninety";
        case 1000: return "onethousand";
        default:
            {
                string toReturn;
                if(number<100)
                    toReturn = toWords(number-number%10) + toWords(number%10);  //using recursion to build the string...
                else
                    toReturn = toWords(number/100)+"hundred"+ ((number/100*100!=number)?"and":"") + toWords(number%100);
                return toReturn;
            }
    }
}

int main() {
    long count = 0;
    int testnum;
    cin>>testnum;
    cout<<toWords(testnum);
    cout<<toWords(testnum).length()<<endl;
    for(long i = 1; i<=MAX_NUM; i++)
        count+=toWords(i).length();
    cout<<count;
    return 0;
}
