class DeckOfCards:
    def __init__ (self, L):
        self.L = L

    def dealTop(self):
        return self.L.pop(0)

    def dealBottom(self):
        return self.L.pop(-1)

    def addTop(self, card):
        L.append(card)

    def addBottom(self, card):
        L.insert(0, card)

    def addPileTop(self, pile):
        L = pile + L

    def addPileBottom(self, pile):
        L = L + pile

    def deal(self, nplayers, ncards = None):
        
        

    def __len__(self):
        
        
    
