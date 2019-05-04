from math import sqrt, floor

num = int(input("Enter num: "))
next = sqrt(num)
cont_terms = []
cont_terms.append(floor(next))

for i in range(1000):
    next = 1/(next - cont_terms[i])
    cont_terms.append(floor(next))

print("Square root as continued fraction:", cont_terms)