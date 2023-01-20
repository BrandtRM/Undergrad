### (Divide and conquer)
## One of the 3^n (3 to the power of n) parts is defective. Its weight is
## different from all the other parts. The parts that are not defective all
## have the same weight. There is a scale we can use that can
## tell whether two groups of parts have the same total weight. We use the
## function isequal(A, B) to simulate this scale. Our goal here is to use the
## scale to find out which part is defective, at the same time minimize the
## number of times that we use the scale. The weights of all the parts are
## stored in a list L.

def isequal(A, B):
    return sum(A) == sum(B)

def finddefect(L, left=0, right=None):
    if right == None: right = len(L)

    if right - left == 1: return left

    length = right - left
    A = L[left : left + length//3]
    B = L[left + length//3 : left + length*2//3]
    C = L[left + length*2//3 : left + length]
    ### Fill in your code below
    if len(L) == 3:
        if isequal(A, B):
            return right - 1
        elif isequal(B, C):
            return left
        else:
            return right - left - 2
    else:
        if isequal(A, B):
            return finddefect(C) + 6
        elif isequal(B, C):
            return finddefect(A) + 0
        else:
            return finddefect(B) + 3
    




L = [2, 1, 1]
print(finddefect(L))

L = [1, 2, 1]
print(finddefect(L))

L = [1, 1, 2]
print(finddefect(L))

L = [2, 1, 1, 1, 1, 1, 1, 1, 1]
print(finddefect(L))

L = [1, 1, 1, 1, 1, 1, 1, 2, 1]
print(finddefect(L)) 

L = [1, 1, 1, 1, 1, 1, 1, 1, 2]
print(finddefect(L))
