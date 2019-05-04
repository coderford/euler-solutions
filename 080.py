from math import sqrt

def is_perfect(x):
	if int(sqrt(x))**2 == x:
		return True
	return False

def digit_sqrt(x, digits):
	'''
	Uses long division method to calculate first 'digits' digits of the square root of x.
	If x is a perfect square, only returns the square root's digits, no additional zeroes.
	'''
	r = 0
	p = 0
	for i in range(digits):
		c = r*100 + x%100
		for d in range(10):
			if d*(20*p+d) < c:
				x = d
		y = x*(20*p+x)
		p = p*10 + x
		r = c-y
		if r == 0: break
		x //= 100
		if x == 0: x *= 100
	return p

if __name__ == '__main__':
	total = 0
	for n in range(2, 101):
		if not is_perfect(n):
			x = digit_sqrt(n, 100)
			s = 0
			while(x != 0):
				s += x%10
				x //= 10
			total += s
	print(total)
