### In this code thought problem, we will solve the following mathmatical
### problem.

### A fair, twenty-faced die has 19 of its faces numbered from 1 through 19
### and has one blank face. Another fair, twenty-faced die has 19 of its faces
### numbered from 1 through 8 and 10 through 20 and has one blank face. When
### the two dice are rolled, what is the probability that the sum of the two
### numbers facing up will be 24? Express your answer as a common fraction.

### This is from my daughter's mathcounts problems.
### It is a good idea that you solve it using your brain first and then using
### your computer :)

import random

def is24():

    ### Below we use two lists to describe the two dice
    die1 = [ i for i in range(20)]
    die2 = [ i for i in range(21) if i is not 9]
 
    ### Note how we initilize the two lists above
    ### We are using list comprehension here
    ### Try to understand how these list comprehensions work
    ### Essentially, within the square brackets, you are just describing what
    ### elements should be included in this list

    ### To simplify the implementation, we use 0 to represent the blank face
    ### It would not cause any trouble for our specific problem here
    
    ### Note in the following we use len(die1) and len(die2) instead of 20
    ### This is a good style, and sometimes this can avoid unnecessary mistakes
    
    d1 = random.randrange(len(die1))
    d2 = random.randrange(len(die2))

    ### fill in your code below to finish this function
    if (0<=d2<=8 and d1==(24-d2)):
        return 1
    elif (10<=(d2+1)<=20 and d1==(23-d2)):
        return 1
    else:
        return 0
        

### We use a simulation to estimate the probability described in the problem
### We roll the two dice 100 thousand times and check how many times the sum
### of the faces of the two dice is 24
    
trials = 100000
random.seed(15)
s = 0
for i in range(trials):
    s += is24()

print("The estimate of the probability is")
print(s/trials)






