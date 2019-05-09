// Wrote this back-tracking solution after observing that the required primes are quite rare.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(long long x) {
    if(x < 2) return false;
    long long s = sqrt(x);
    for(long long i = 2; i <= s; i++)
        if(x % i == 0) return false;
    return true;
}

int digit_sum(long long x) {
    int sum = 0;
    while(x > 0) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

bool is_harshad(long long x) {
    if(x == 0) return false;
    return (x % digit_sum(x) == 0);
}

bool is_strong_harshad(long long x) {
    if(!is_harshad(x)) return false;
    return is_prime(x / digit_sum(x));
}

ll ans = 0;                 // sum is stored here
void add_primes(ll x) {
    // given a number, adds all prime numbers formed by appending a digit 
    // (to the right) to ans
    for(int i = 1; i < 10; i+=2) {
        if(is_prime(x*10 + i)) ans += x*10 + i;
    }
}

ll cur = 0;
void solve(ll lim) {        // maintains right-truncatability
    if(cur > lim/10) return;// need /10 because cur must have 1 digit less
    if(cur != 0) {
        if(is_strong_harshad(cur)) {
            add_primes(cur);
        }
    }
    for(int i = 0; i < 10; i++) {
        cur = cur*10 + i;
        if(is_harshad(cur)) solve(lim);
        cur /= 10;
    }
}

int main(int argc, char *argv[]) {
    ll lim = 10000;
    if(argc > 1) lim = atoll(argv[1]);
    solve(lim);
    cout << ans << '\n';
    return 0;
}
