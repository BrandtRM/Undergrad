### In the first part of the assignment, we read the following code and then
### run the code.
### Do we see the expected output? Why?

### Next, we fix the code so that it generates the expected output.

L = [i for i in range(10)]

### We want to print out the reversed list L
L.reverse()
print(L)
### What do you learn about functions(methods) from this part of the assignment?

### Next, we will implement a function to reverse a list
### Do you see the expected output? Why?

### Next, we fix the code so that it generates the expected output.
def listreverse(L):
    L1 = L.copy()
    L = []
    for i in L1:
        L.append(L1.pop())

listreverse(L)
### We want to print out the reversed list L
print(L)
