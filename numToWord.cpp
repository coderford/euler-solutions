//converts any number from 1 to 1000 to its word form
#include <iostream>
#include <string>
using namespace std;

string toWords(int number) {
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
        case 1000: return "one thousand";
        default:
            {
                string toReturn;
                if(number<100)
                    toReturn = toWords(number-number%10) + " " + toWords(number%10);  //using recursion to build the string...
                else
                    toReturn = toWords(number/100)+" hundred"+ ((number/100*100!=number)?" and ":"") + toWords(number%100);
                return toReturn;
            }
    }
}
int main() {
    int userInput;
    cout<<"Enter a number: ";
    cin>>userInput;
    cout<<"Your number in words: "<<toWords(userInput);
    return 0;
}
