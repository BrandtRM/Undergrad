def findmin(L, k = 1):
    left = 0
    right = len(L) - 1
    while right - left > 1:
        mid = (right + left + 1) // 2
        print(L[left], L[mid], L[right])
        if L[left] == 0 or L[mid] == 0 or L[right] == 0:
            return 0
        elif L[right] > L[mid] and min(L[mid:right+1]) == L[mid]:
            right = mid
        else:
            left = mid
    return right > left and L[mid]

def firstrepeat(L, i):
    item = L[i]
    left = 0
    right = len(L) - 1
    poss = []
    mid = (left + right + 1) // 2
    
    for j in range(left, mid):
        if L[mid] == item:
            poss.append(mid)
        if L[j] == item:
            poss.append(j)
        if L[right - j] == item:
            poss.append(right - j)
    return min(poss)

    
def lastrepeat(L, i):
    item = L[i]
    left = 0
    right = len(L) - 1
    poss = []
    mid = (left + right + 1) // 2

    for j in range(left, mid):
        if L[mid] == item:
             poss.append(mid)
        if L[j] == item:
            poss.append(j)
        if L[right - j] == item:
            poss.append(right - j)
    return max(poss)
