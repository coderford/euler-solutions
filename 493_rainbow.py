import sys
from math import factorial as f

def C(n, r):
    return f(n)//(f(n-r)*f(r))

partitions = []
def make_splits_actual(x, cur, rem):
    '''
        Stores all partitions of 20 into x parts, each part being <= 10 
    '''
    global partitions
    if len(cur) == x:
        partitions.append(tuple(cur))
        return
    for i in range(max(1, rem - (x - len(cur) - 1)*10), min(rem, 10)+1):
        cur.append(i)
        make_splits_actual(x, cur, rem-i)
        cur.__delitem__(len(cur)-1)

def make_splits(x):
    ''' 
        [WRAPPER] Initializes partitions array and calls the actual function 
    '''
    global partitions
    partitions = []
    make_splits_actual(x, [], 20)

def combos_with_distinct(x):
    '''
        Returns number of ways to select 20 balls so that x distinct balls are present
    '''
    global partitions
    make_splits(x)
    total = 0
    for p in partitions:
        combos = 1
        for x in p:
            combos *= C(10, x)
        total += combos
    return total

num = 0
denom = 0
for cols in range(2, 7 + 1):
    combos = C(7, cols) * combos_with_distinct(cols)
    num += cols * combos
    denom += combos

print('%.9f'%(round(num/denom, 9)))
