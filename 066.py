'''
	x^2 - D*y^2 = 1
	solve(d) finds the minimal value of x and y that fits the equation for 
	D = d and returns the value of x

	Keywords: diophantine equation, 66, pell's, pell, quadratic
'''
from math import sqrt
import pells_equation

def is_perfect_sq(x):
	if int(sqrt(x))**2 == x:
		return True
	return False

def solve(d):
	y = 1
	while True:
		x2  = d*(y**2)+1
		if is_perfect_sq(x2): return (int(sqrt(x2)), y)
		y += 1

if __name__ == '__main__':
	lim = 1000000
	xmax = 0
	dmax = 0
	for d in range(13, lim+1):
		if not is_perfect_sq(d):
			x, y = pells_equation.solve(d)
			if x > xmax:
				xmax = x
				dmax = d
	print('D = %d, x = %d'%(dmax, xmax))
