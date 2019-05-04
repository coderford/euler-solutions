def factorial(x):
    fact = 1
    i = 1
    while i<=x:
        fact *= i
        i += 1
    return fact

def combinations(n, r):
    return factorial(n)/(factorial(n-r)*(factorial(r)))

n = 1
count = 0
while n<=100:
    r = 1
    while r<=n:
        if combinations(n, r) > 1000000:
            count += 1
        r += 1
    n += 1

print(count)
