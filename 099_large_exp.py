import csv
import sys
from math import log10

def log_pow(base, exp):
    return exp*log10(base)

max_val = 0
max_base = 0
max_exp = 0
filename = "p099_base_exp.txt"
with open(filename) as datafile:
    reader = csv.reader(datafile)
    for row in reader:
        if log_pow(int(row[0]), int(row[1]))>max_val:
            max_val = log_pow(int(row[0]), int(row[1]))
            max_base = int(row[0])
            max_exp = int(row[1])

datafile.close()
print("max is {base}^{exp}".format(base = max_base, exp = max_exp))
