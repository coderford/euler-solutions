def fact(n):
	if n <= 1:
		return 1
	return n*fact(n-1)

def check(n):
	string = str(n)
	i = 0
	sum = 0
	while i<len(string):
		sum+=fact(int(string[i]))
		i+=1
	#print("for n: {num}, the sum is {sum}".format(num=n, sum = sum))
	if sum == n:	#don't use 'is' instead of '==' ! they have some subtle difference in their functions...
		return True	#turns out that 'is' is true only when two vars refer to the same object!!
	else:
		return False
		
i = 9
sum = 0
while i<3000000:
	if check(i) is True:
		sum+=i
		print(i)
	i+=1

print("The sum is {sum}".format(sum = sum))