from math import sqrt

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
	calculates convergent from given recurring representation of 
	continued fraction

	Note: if terms = 0, and continued fraction is [a0, a1, ... ak]
		  calculates upto a1
		  for terms = 1 calculates upto a2

		  so to calculate upto ai input terms = i-1
		  This problem can be removed by revising the implementation...
		  i'm lazy
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

def solve(d):
	f = continued_fraction(d)
	k = len(f) - 1
	if k%2 == 0:
		return convergent(f, k-1 -1)
	else:
		return convergent(f, 2*k-1 -1)
