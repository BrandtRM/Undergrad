import random

class Distribution():
    def __init__(self):
        self.A = dict()
        self.B = dict()
        self.sum = 0

    def add(self, e, multiplicity = 1):
        if e in self.A:
            self.A[e] += multiplicity
            self.sum += multiplicity
        else:
            self.A[e] = multiplicity
            self.sum += multiplicity
        self.B[e] = self.sum

    def count(self, e):
        return self.A[e]
        
    def prob(self, e):
        return self.A[e] / sum(self.A.values())

    def sample(self):
        x = random.randint(0, self.sum)
        y = list(self.B.values())
        z = list(self.B.keys())
        i = 0
        while i < len(y):
            if x < y[i]:
                return z[i]
            else:
                i += 1

    def __len__(self):
        return sum(self.A.values())



'''class Distribution():
    def __init__(self):
        self.A = dict()
        self.B = dict()
        self.sum = 0

    def add(self, e, multiplicity = 1):
        if e in self.A:
            self.A[e] += multiplicity
            self.sum += multiplicity
        else:
            self.A[e] = multiplicity
            self.sum += multiplicity
        self.B[e] = self.sum

    def count(self, e):
        return self.A[e]
        
    def prob(self, e):
        return self.A[e] / sum(self.A.values())

    def sample(self):
        x = random.randint(0, self.sum)
        sums = list(self.B.values())
        left = sums[0]
        right = sums[-1]
        if x < sums[0]:
            return self.B[left]
        while right - left < 2:
            mid = (left + right) // 2
            if x == mid:
                return self.B[mid]
            elif x < mid:
                right = mid
            elif x > mid:
                left = mid
        return self.B[right]

    def __len__(self):
        return sum(self.A.values())'''
