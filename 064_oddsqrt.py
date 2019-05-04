'''
Explanation of the algorithm to find continued fraction:

l contains the list of repeating integers in continued fraction form of x
a is the addend in the numerator
b is the denominator
-> initially a is -(floor(sqrt(x))) and b is 1
-> extract the next integer term by taking the reciprocal of (sqrt(x) + a)/b
and reducing it to a mixed fraction, then taking out the integer part
assign new a, b and repeat until original a and b occur again

Keywords: continued fraction, square root representation, 64, is perfect square
'''
from math import sqrt

def is_perfect_sq(x):
	if int(sqrt(x))**2 == x:
		return True
	return False

def continued_fraction(x):
	'''
	returns the continued fraction representation of a square root as list
	'''
	l = []
	closest = int(sqrt(x))
	l.append(closest)
	a = -closest
	b = 1
	while True:
		d = (x - a**2)//b
		c = -a
		i = (closest+c)//d
		l.append(i)
		a = c - i*d
		b = d
		if a == -closest and b == 1:
			break
	return l

def convergent(fraction, terms):
	'''
	calculates nth convergent from given recurring representation of 
	continued fraction
	'''
	k = len(fraction) - 1
	recurring = fraction[1:]
	num = recurring[terms % k]
	den = 1
	while terms > 0:
		terms -= 1
		den, num = num, den
		num = recurring[terms % k] * den + num
	start = fraction[0]
	den, num = num, den
	num = start * den + num
	return (num, den)

if __name__ == '__main__':
	lim = 10000
	count = 0
	for i in range(2, lim+1):
		if not is_perfect_sq(i):
			l = continued_fraction(i)
			if len(l)%2 == 0:
				count += 1
	print(count)
