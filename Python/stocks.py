### In this assignment, we simulate how stock trading works.
### We use the priority queue to organize a bid queue and a ask queue.
### We use a bid queue to organize all the buying orders of a stock,
### and we use a ask queue to organize all the selling orders of this stock.
### A trade will occur if the highest bid price exceeds or meets the lowest
### ask price. The trade price is calcualted as the average of these two values.
### To make the problem simple, we assume all the orders are of the size 100
### shares.

class Entry:
    def __init__(self, item, priority):
        self.priority = priority
        self.item = item

    def __lt__(self, other):
        return self.priority < other.priority
    
class PriorityQueue:
    def __init__(self, entries = None):
        entries = entries or []
        self._entries = [Entry(i, p) for i, p in entries]
        self._itemmap = {i: index for index, (i, p) in enumerate(entries)}
        self._heapify()

    def insert(self, item, priority):
        index = len(self._entries)
        self._entries.append(Entry(item, priority))
        self._itemmap[item] = index
        self._upheap(index)

    def _parent(self, i):
        return (i - 1) // 2

    def _children(self, i):
        left, right = 2 * i + 1, 2 * i + 2
        return range(left, min(len(self._entries), right + 1))

    def _swap(self, a, b):
        L = self._entries
        va = L[a].item
        vb = L[b].item
        self._itemmap[va] = b
        self._itemmap[vb] = a
        L[a], L[b] = L[b], L[a]

    def _upheap(self, i):
        L = self._entries
        parent = self._parent(i)
        if i > 0 and L[i] < L[parent]:
            self._swap(i, parent)
            self._upheap(parent)

    def reducepriority(self, item, priority):
        i = self._itemmap[item]
        entry = self._entries[i]
        entry.priority = min(entry.priority, priority)
        self._upheap(i)

    def findmin(self):
        return self._entries[0].item

    def removemin(self):
        L = self._entries
        item = L[0].item
        self._swap(0, len(L) -1)
        L.pop()
        self._downheap(0)
        return item

    def _downheap(self, i):
        L = self._entries
        children = self._children(i)
        if children:
            child = min(children, key = lambda x: L[x])
            if L[child] < L[i]:
                self._swap(i, child)
                self._downheap(child)

    def __len__(self):
        return len(self._entries)

    def _heapify(self):
        n = len(self._entries)
        for i in range(n):
            self._downheap(n - i - 1)

    def getentries(self):
        return self._entries

    def remove(self, item):
        i = self._entries.index(item)
        j = len(self._entries)
        self._entries[i] = self._entries[j-1]
        self._entries.pop()
        self._downheap(i)                                                           

def stocktrading(bid, ask):

    trade_L = []
    
    bid_L = []
    for item in bid:
        ## Add one line of code here
        bid_L.append((item, -item[0]))


    bid_q = PriorityQueue(bid_L)

    ask_L = []
    for item in ask:
        ## Add one line of code here
        ask_L.append((item, item[0]))


    ask_q = PriorityQueue(ask_L)

    print("Highest bid:")
    print(bid_q.findmin())
    print("Lowest ask:")
    print(ask_q.findmin())

    while bid_q.findmin() >= ask_q.findmin():
        print("Last Trade:")
        print(ask_q.findmin()[1], "shares at", (ask_q.findmin()[0] + bid_q.findmin()[0])/2)
        print("*********************")
        trade_L.append((ask_q.findmin()[1], (ask_q.findmin()[0] + bid_q.findmin()[0])/2))
        
        ## Add two lines of code here
        bid_q.removemin()
        ask_q.removemin()
            

       
        print("Highest bid:")
        print(bid_q.findmin())
        print("Lowest ask:")
        print(ask_q.findmin())
        
    return trade_L

## The following are buying orders
## In each tuple, the first item is price, and the second item is the number
## of shares

bid = [(90.00, 100), (91.00, 100), (89.00, 100), (78.50, 100), (80.00, 100)]

## The following are selling orders
ask = [(99.00, 100), (95.00, 100), (88.00, 100), (89.00, 100), (85.00, 100)]

stocktrading(bid, ask)

    
    
