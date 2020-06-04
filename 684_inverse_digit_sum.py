'''
PROBLEM 684 - INVERSE DIGIT SUM

Define s(n) to be the smallest number that has a digit sum of n. For example s(10)=19.
Let S(k) = ∑(n=1->k) s(n). You are given S(20)=1074

Further let f(i) be the Fibonacci sequence defined by f(0)=0,f(1)=1 and f(i)=f(i−2)+f(i−1) for all i≥2.

Find ∑(i=2->90) S(f(i))

Give your answer modulo 1000000007.
'''

from utils import powmod

fibtable = [0, 1]
def fib(n):
    while len(fibtable) <= n:
        fibtable.append(fibtable[-1] + fibtable[-2])
    return fibtable[n]

def S(n, M):
    '''
    This formula can be derived by taking
        s(n) = (n % 9 + 1)*(10**(n//9)) - 1
    and then taking the sum over [1, n] to get S(n)
    '''
    q = n // 9
    r = n % 9
    pow10q = powmod(10, q, M)

    ans = 5*((pow10q - 1)%M)
    ans = (ans + (r + 1)*(r + 2)//2 * pow10q)%M
    ans = (ans - (n+1))%M
    return ans

if __name__ == '__main__':
    M = int(1e9 + 7)
    total = 0
    for i in range(2, 91):
        total = (total + S(fib(i), M))%M
    print(total)
