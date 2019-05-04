def digit_sum(x):
    string = str(x)
    i = 0
    sum = 0
    while i<len(string):
        sum += int(string[i])
        i+=1
    return sum

max = 0
a = 1
while a<100:
    b = 1
    while b<100:
        sum = digit_sum(a**b)
        if sum>max:
            max = sum
        b+=1
    a+=1

print(max)
