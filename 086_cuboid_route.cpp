#include <iostream>
#include <cmath>
using namespace std;

bool is_perfect_square(int x) {
    int s = sqrt(x);
    return (s*s) == x;
}

int square_of_shortest(int a, int b, int c) {
    int s1 = (a+b)*(a+b) + c*c;   
    int s2 = (b+c)*(b+c) + a*a;   
    int s3 = (c+a)*(c+a) + b*b;   
    return min(min(s1, s2), s3);
}

bool is_triplet_ok(int a, int b, int c) {
    return is_perfect_square(square_of_shortest(a, b, c));
}

int count_solutions(int lim) {
    int count = 0;
    for(int i = 1; i <= lim; i++)
        for(int j = i; j <= lim; j++)
            for(int k = j; k <= lim; k++)
                count += is_triplet_ok(i, j, k);
    return count;
}

int main() {
    // binary searching on value of count_solutions()
    int required = 1000000;
    int beg = 1, end = 3000;
    int mid = (beg + end)/2;
    while(true) {
        if(mid > end || mid < beg) break;
        int currcount = count_solutions(mid); 
        if(currcount > required) {
            end = mid;
            if(count_solutions(mid-1) < required) break;
            if(end == beg) break;
        }
        else if(currcount < required) {
            beg = mid + 1;
        }
        else break;
        mid = (beg + end)/2;
    }
    if(mid >= beg && mid <= end) cout << mid;
    else cout << "Solution not found in range.\n";
    return 0;
}
