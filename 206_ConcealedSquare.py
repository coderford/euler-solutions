'''
Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
where each “_” is a single digit.
'''
#lame brute force method: just taking square in a range and checking form...
import datetime

def checkSquare(num):
    string = str(num)
    if string[0] is '1' and string[2] is '2' and string[4] is '3' and string[6] is '4' and string[8] is '5' and string[10] is '6' and string[12] is '7' and string[14] is '8' and string[16] is '9' and string[18] is '0':
        return True
    return False

start = datetime.datetime.now()
found = False
i = 10**9

while i<10**10:
    square = i*i
    if checkSquare(square):
        found = True
        break
    i+=1

if found:
    print(i)
else:
    print("Not found!")

end = datetime.datetime.now()
time_taken = start.hour*3600+start.minute*60+start.second - end.hour*3600+end.minute*60+end.second
print("Time: {time} seconds".format(time=time_taken))
