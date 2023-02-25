def swaps(L, key = lambda x: x):
    fake = []
    for x in L:
        fake.append(key(x))

    if len(fake) < 2:
        return 0
    else:
        mid = len(fake)//2
        A = fake[:mid]
        B = fake[mid:]

        i = 0
        j = 0

        C = swaps(A)
        D = swaps(B)
        count = C + D
        
    while i < len(A) and j < len(B):
        if A[i] < B[j]:
            i += 1
        elif A[i] == B[j]:
            count += j - i + 1
            i += 1
        else:
            j += 1
            count += len(A) - i
    return count

