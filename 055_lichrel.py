def is_lichrel(x):
    i = 0
    while i<50:
        x = x + int(str(x)[::-1])
        if x == int(str(x)[::-1]):
            return False
        i+=1
    return True

count = 0
i = 1
while i<10000:
    if is_lichrel(i):
        count+=1
    i+=1

print(count)
