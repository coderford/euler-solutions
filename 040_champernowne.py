'''an irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000'''

string = "1"
i = 2
while len(string)<1000000:
    string = string + str(i)
    i+=1

j = 0
product = 1
while j<=6:
    product*=int(string[10**j-1])
    j+=1

print(product)
