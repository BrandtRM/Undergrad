class ListNode:
    def __init__(self, data, prev = None, link = None):
        self.data = data
        self.prev = prev
        self.link = link
        if prev is not None:
            self.prev.link = self
        if link is not None:
            self.link.prev = self

class DeckOfCards:
    def __init__(self, L = None):
        self._head = None
        self._tail = None
        self._length = 0

        if L:
            for item in L:
                self.addlast(item)
    
    def _addbetween(self, item, before, after):
        node = ListNode(item, before, after)
        if after is self._head:
            self._head = node
        if before is self._tail:
            self._tail = node
        self._length += 1

    def addfirst(self, item):
        self._addbetween(item, None, self._head)
        
    def addlast(self, item):
        self._addbetween(item, self._tail, None)

    def _remove(self, node):
        before, after = node.prev, node.link
        if node is self._head:
            self._head = after
        else:
            before.link = after
        if node is self._tail:
            self._tail = before
        else:
            after.prev = before
        self._length -= 1
        return node.data

    def dealTop(self):
        return self._remove(self._head)

    def dealBottom(self):
        return self._remove(self._tail)
    
    def __len__(self):
        return self._length

    def addTop(self, card):
        return self.addfirst(card)

    def addBottom(self, card):
        return self.addlast(card)

    def addPileTop(self, pile):
        pile._tail.link = self._head
        self._head = pile._head
        pile._head = None
        pile._tail = None
        p = []
        d = []     
        
        
    def addPileBottom(self, pile):
        self._tail.link = pile._head
        self._tail = pile._tail
        pile._head = None
        pile._tail = None
        p = []
        d = []

    #def deal(self, nplayers, ncards = None):
        

