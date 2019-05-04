def add(frac1, frac2):
    return [frac1[0]*frac2[1]+frac1[1]*frac2[0], frac1[1]*frac2[1]]

def multiply(frac1, frac2):
    return [frac1[0]*frac2[0], frac1[1]*frac2[1]]

def reciprocal(frac):
    return [frac[1], frac[0]]

def inverse(frac):
    return [-frac[0], frac[1]]

def divide(frac1, frac2):
    return multiply(frac1, reciprocal(frac2))

def sqrt_2(iterations):
    last_term = [5, 2]
    for i in range(iterations-1):
        last_term = add([2,1], divide([1,1], last_term))
    last_term = add(last_term, [-1, 1])
    return last_term
	

count = 0
for i in range(1, 1001):
	sq2 = sqrt_2(i)
	if len(str(sq2[0])) > len(str(sq2[1])):
		count+=1

print(count)

