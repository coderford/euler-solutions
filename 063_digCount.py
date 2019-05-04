from math import ceil, log10
def digit_count(x):
  return len(str(x))

count = 0
for i in range(1, 10):
    j = 1
    while(True):
        if digit_count(i**j)==j:
            print(i**j, j)
            count+=1
            j+=1
        else: break

print(count+1)
