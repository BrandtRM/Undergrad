from pq import PriorityQueue

class MyPQ(PriorityQueue):
    def findtopk(self, k):
        fake = self._entries
        answr = []
        if len(self._entries) <= k:
            for x in range(0, self._entries):
                y = self.removemin()
                answr.append(y)
            return answr
        else:
            for x in range(0,k):
                y = self.removemin()
                answr.append(y)
            return answr
        self._entries = fake
        self._heapify()

    def removetopk(self, k):
        answr = []
        if len(self._entries) <= k:
            for x in range(0, self._entries):
                y = self.removemin()
                answr.append(y)
            return answr
        else:
            for x in range(0,k):
                y = self.removemin()
                answr.append(y)
            return answr

    def changepriority(self, item, newpriority):
        for x in self._entries:
            if x.item == item:
                x.priority = newpriority
                self._heapify()
            
    def remove(self, item):
        for x in self._entries:
            if x.item == item:
                y = x
        i = self._entries.index(y)
        j = len(self._entries)
        self._entries[i] = self._entries[j-1]
        self._entries.pop()
        self._downheap(i)      

    def insert(self, item, priority):
        y = 0
        for x in self._entries:
            if x.item == item:
                y = 1
        if y != 1:
            PriorityQueue.insert(self, item, priority)
        else:
            self.changepriority(item, priority)


