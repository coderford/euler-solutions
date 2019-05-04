/*Euler discovered the remarkable quadratic formula:

n2+n+41

It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39
. However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41

is clearly divisible by 41.

The incredible formula n2−79n+1601
was discovered, which produces 80 primes for the consecutive values 0≤n≤79

. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n2+an+b

, where |a|<1000 and |b|≤1000

where |n|
is the modulus/absolute value of n
e.g. |11|=11 and |−4|=4

Find the product of the coefficients, a
and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
*/



//It turns out that the other formula, n*n - 79*n +1601 is just an x translation of euler's formula:
    //(n-40)^2+(n-40)+41
//It seems that euler's formula is the only one which touches on so many primes
//Also, note that the required expression at n = 0 must be a prime less than 1000
//generating the list of primes with the second quadratic equation, it was easy to find how much_
//the expression should be shifted to get the maximum b which is a prime and false on the curve
//this value was 971 and the corresponding value of a was -61, the shift being 30
//so the require expression is n*n-61*n+971, it generates 71 prime numbers
