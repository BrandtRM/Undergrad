## Find the Rotation Count in Rotated Sorted List
## Consider an list of distinct numbers sorted in increasing order. The list has been rotated (anti-clockwise)
## k number of times. Given such a list, find the value of k.
## An example:
## Input : L = [15, 18, 2, 3, 6, 12]. Output: 2.
## Explanation:
## Initial list must be [2, 3, 6, 12, 15. 18]. We get the given list after rotating the initial list twice.
## More examples:
## Input : L = [7, 9, 11, 12, 5]. Output: 4.
## Input: L = {7, 9, 11, 12, 15]. Output: 0.
## Input: L = []. Output: 0.
## Input: L = [1]. Output: 0.
## Implement the function rotationcount, so that code like the following can work correctly
## print(rotationcount([7, 9, 11, 12, 5]))
## The running time of the function needs to be O(log n), where n is the size of the input list.
## To help you start, below is the binary search code from the textbook. ​Hint: only minor changes needed.
def bs(L, item):
    left, right = 0, len(L)
    while right - left > 1:
        median = (left + right) // 2
        if item < L[median]: right = median
        else: left = median
    return right > left and L[left] == item

def rotatecount(L):
    # fill in your code below
    left, right = 0, len(L) - 1
    if len(L) == 0 or len(L) == 1:
        return 0
    if len(L) == 2:
        if L[left] < L[right]:
            return 0
        else:
            return 1
    while right - left > 1:
        median = (left + right) // 2
        if (median < right and L[median + 1] < L[median]):
            return median + 1
        elif(median > left and L[median] < L[median - 1]):
            return median
        elif L[right] > L[median]:
            right = median
        else:
            left = median
    return 0





L = [1, 2, 3, 4, 5, 6]
print(L)
print(rotatecount(L))
L = [7, 9, 11, 12, 5]
print(L)
print(rotatecount(L))
L = [15, 18, 2, 3, 6, 12, 14]
print(L)
print(rotatecount(L))
L = [10, 1, 2, 3, 4]
print(L)
print(rotatecount(L))
L = [1]
print(L)
print(rotatecount(L))
L = [2, 1]
print(L)
print(rotatecount(L))
L = [2, 3, 1]
print(L)
print(rotatecount(L))
L = [1, 2, 3]
print(L)
print(rotatecount(L))
L = [3, 1, 2]
print(L)
print(rotatecount(L))
L = [2, 3, 4, 1]
print(L)
print(rotatecount(L))
L = [3, 4, 1, 2]
print(L)
print(rotatecount(L))
L = [5, 6, 1, 2, 3, 4]
print(L)
print(rotatecount(L))
L = [3, 1, 2]
print(L)
print(rotatecount(L))
L = [2, 3, 1]
print(L)
print(rotatecount(L))
L = []
print(L)
print(rotatecount(L))

