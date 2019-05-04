def count_laminae(hole_size, max_squares):
    max_lamina_side = int((max_squares+hole_size**2)**0.5)
    min_lamina_side = hole_size+2;
    return (max_lamina_side-min_lamina_side)//2 + 1

max_squares = 1000000
hole_size = 1
sum = 0

while(hole_size<=max_squares):
    count = count_laminae(hole_size, max_squares)
    if count==0:
        break
    sum += count
    hole_size += 1

print(sum)