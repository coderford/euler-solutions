i = 3
arrs = [[],[],[1,1]]
while True:
    new_arr = []
    for j in range(1,i):
        new_arr.append(sum(arrs[i-j][j-1:])%1000000)
    new_arr.append(1)
    arrs.append(new_arr)
    ans = sum(arrs[-1])%1000000
    #bbprint(i, ans)
    if ans == 0:
        print(i)
        break
    i += 1

