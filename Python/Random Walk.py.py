import sys
import numpy
import random

#set array to store distance for 100 trials
dist = [0 for x in range(100)]

#loop for 100 trials
for i in range(0, 100):
    #set array of size 101 by 101 where (51, 51) is the origin
    field = numpy.zeros([101, 101], dtype = int)
    count = 0
    
    #set center values
    x = 51
    y = 51

    #loop until a boundary is reached or all adjacent moves are already made
    while(field[x + 1][y] == 0 or field[x - 1][y] == 0 or field[x][y + 1] == 0 or field[x][y - 1] == 0 and x > 0 and x < 101 and y > 0 and y < 101):
        field[x][y] = 1
        n = random.randint(0, 3)
        
        if(n == 0):
            y += 1
        elif(n == 1):
            x += 1
        elif(n == 2):
            y -= 1
        else:
            x -= 1
        
        count += 1
    dist[i] = count

#Solution
print("For 100 trials with lattice size 100 X 100:")
print()
print("Average path length: ", numpy.average(dist))
print("Standard deviation of path length: ", round(numpy.std(dist), 2))
print()
print()



#set array to store distance for 100 trials
dist = [0 for x in range(100)]

#loop for 100 trials
for i in range(0, 100):
    #set array of size 1001 by 1001 where (501, 501) is the origin
    field = numpy.zeros([1001, 1001], dtype = int)
    count = 0
    
    #set center values
    x = 501
    y = 501
    
    #loop until a boundary is reached or all adjacent moves are already made
    while(field[x + 1][y] == 0 or field[x - 1][y] == 0 or field[x][y + 1] == 0 or field[x][y - 1] == 0 and x > 0 and x < 1001 and y > 0 and y < 1001):
        field[x][y] = 1
        n = random.randint(0, 3)
        
        if(n == 0):
            y += 1
        elif(n == 1):
            x += 1
        elif(n == 2):
            y -= 1
        else:
            x -= 1
        
        count += 1
    dist[i] = count

#Solution
print("For 100 trials with lattice size 1000 X 1000:")
print()
print("Average path length: ", numpy.average(dist))
print("Standard deviation of path length: ", round(numpy.std(dist), 2))


