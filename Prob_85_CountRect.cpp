/*

By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:

Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.
*/
#include <iostream>
#include <cmath>
using namespace std;

int rect_count(int p_base, int p_height, int base, int height) {
    if(base>p_base||height>p_height)
        return 0;
    int horizontally = 1 + (p_base - base);
    int vertically = 1 + (p_height - height);
    return horizontally * vertically;
}

int total_count(int p_base, int p_height) {
    int sum = 0;
    for(int i = 1; i<=p_base; i++)
        for(int j = 1; j<=p_height; j++)
            sum += rect_count(p_base, p_height, i, j);
    return sum;
}

int main() {
    int target_count = 2000000;
    int closest_base = 0;
    int closest_height = 0;
    int curr_diff = 1000000;
    for(int i = 1; i<100; i++)  //guessing that the closest base and height_
        for(int j = 1; j<100; j++) {    //should be smaller than 100...
            int new_diff = abs(total_count(i, j)-target_count);
            if(new_diff<curr_diff) {
                curr_diff = new_diff;
                closest_base = i;
                closest_height = j;
            }
        }
    cout<<"base = "<<closest_base<<endl;
    cout<<"height = "<<closest_height<<endl;
    cout<<"area = "<<closest_base*closest_height<<endl;
    cout<<"count = "<<total_count(closest_base, closest_height)<<endl;
    return 0;
}
