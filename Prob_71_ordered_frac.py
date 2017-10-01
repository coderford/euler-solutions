def max_num(x):
    return int(x*3/7)

max = 0
the_num = 0
the_denom = 0

for i in range(1, 1000001):
    if max_num(i)/i > max and max_num(i)/i<(3/7):
        max = max_num(i)/i
        the_num = max_num(i)
        the_denom = i

print("{num}/{denom}".format(num = the_num, denom = the_denom))
