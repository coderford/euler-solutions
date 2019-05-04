'''
It is possible to write five as a sum in exactly six different ways:
4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1
How many different ways can one hundred be written as a sum of at least two positive integers?
'''

def partitions(n):
	if(n < 3):
		return n;
	arrs = [[],[],[1,1]]
	for i in range(3, n+1):
		new_arr = []
		for j in range(1,i):
			new_arr.append(sum(arrs[i-j][j-1:]))
		new_arr.append(1)
		arrs.append(new_arr)
	return sum(arrs[-1])

#print(arrs)
print(partitions(int(input())))
