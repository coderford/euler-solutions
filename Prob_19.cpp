/*

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/
#include <iostream>
#include <string>
using namespace std;

const int INIT_WEEKDAY = 1;         //1 for monday, 2 for tuesday... so on till 7 for sunday...
const int INIT_MONTHDAY = 1;
const int INIT_MONTH = 1;           //1 for jan, 12 for dec
const int INIT_YEAR = 1900;
bool isLeap(int year);

int main() {                        //brute-forcing again.. there must be a formula...
    int curr_weekday = INIT_WEEKDAY;
    int curr_monthday = INIT_MONTHDAY;
    int curr_month = INIT_MONTH;
    int curr_year = INIT_YEAR;
    int input_monthday = 31;
    int input_month = 12;
    int input_year = 2000;
    int month_lengths[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int first_sun_count = 0;
    /*cout<<"Enter the date: (dd/mm/yyyy): ";
    cin>>input_monthday;
    cin.ignore(1);
    cin>>input_month;
    cin.ignore(1);
    cin>>input_year;*/
    while(true) {
        if(isLeap(curr_year)) {
            month_lengths[1] = 29;
        }
        else month_lengths[1] = 28;
        if(curr_monthday==input_monthday&&curr_month==input_month&&curr_year==input_year) {
            break;
        }
        if(curr_monthday==1&&curr_weekday==7&&curr_year>1900) {
            cout<<curr_monthday<<"/"<<curr_month<<"/"<<curr_year<<endl;
            first_sun_count++;
        }

        curr_monthday++;
        curr_weekday++;
        if(curr_weekday>7)
            curr_weekday=1;
        if(curr_monthday>month_lengths[curr_month-1]) {
            curr_monthday = 1;
            curr_month++;
        }
        if(curr_month>12) {
            curr_month = 1;
            curr_year++;
        }

    }
    cout<<first_sun_count;
}

bool isLeap(int year) {
    if(year%100!=0) {
        if(year%4==0)
            return true;
    }
    else if(year%400==0)
            return true;
    return false;
}
