from fractions import Fraction
import itertools
import sys
ops = ['+', '-', '*', '/']
d = {'A': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6' : 6, '7': 7, '8': 8, '9': 9, '0': 10, 'J': 11, 'Q': 12, 'K': 13}

class BNode:
    def __init__(self, element):
        self.element = element
        self.left = None
        self.right = None

    def addleft(self, leftnode):
        self.left = leftnode

    def addright(self, rightnode):
        self.right = rightnode

    def evaluate(self):
        ## Add your code here
        if self.element in d:
            return d[self.element]
        else:
            A = self.left.evaluate()
            B = self.right.evaluate()
        if self.element == '+':
            return A + B
        elif self.element == '-':
            return A - B
        elif self.element == '*':
            return A * B
        elif self.element == '/':
            return Fraction(A, B)
            
  
    def display(self):
        ## Add your code here
        if self.element in d:
            return d[self.element]
        else:
            A = self.left.display()
            B = self.right.display()
        if self.element == '+':
            return '(%s+%s)' %(A,B)
        elif self.element == '-':
            return '(%s-%s)' %(A,B)
        elif self.element == '*':
            return '(%s*%s)' %(A,B)
        elif self.element == '/':
            return '(%s/%s)' %(A,B)



def evaluatefive(ops, cards):

    s = set()
    # Tree #1        
    node1 = BNode(ops[0])
    node2 = BNode(ops[1])
    node3 = BNode(ops[2])
    node1.addleft(node2)
    node1.addright(node3)

    node4 = BNode(cards[0])
    node5 = BNode(cards[1])

    node6 = BNode(cards[2])
    node7 = BNode(cards[3])

    node2.addleft(node4)
    node2.addright(node5)

    node3.addleft(node6)
    node3.addright(node7)

    if node1.evaluate() == 24:
        s.add(node1.display())



    # Tree #2
    ## Add your code here     
    node1 = BNode(ops[0])
    node2 = BNode(ops[1])
    node3 = BNode(ops[2])
    node1.addleft(node2)
    node2.addleft(node3)

    node4 = BNode(cards[0])
    node5 = BNode(cards[1])

    node6 = BNode(cards[2])
    node7 = BNode(cards[3])

    node3.addleft(node4)
    node3.addright(node5)

    node2.addright(node6)
    node1.addright(node7)

    if node1.evaluate() == 24:
        s.add(node1.display())



    #tree #3
    ## Add your code here
    node1 = BNode(ops[0])
    node2 = BNode(ops[1])
    node3 = BNode(ops[2])
    node1.addleft(node2)
    node2.addright(node3)

    node4 = BNode(cards[0])
    node5 = BNode(cards[1])

    node6 = BNode(cards[2])
    node7 = BNode(cards[3])

    node2.addleft(node4)
    node3.addleft(node5)

    node3.addright(node6)
    node1.addright(node7)

    if node1.evaluate() == 24:
        s.add(node1.display())



    #tree #4
    ## Add your code here  
    node1 = BNode(ops[0])
    node2 = BNode(ops[1])
    node3 = BNode(ops[2])
    node1.addright(node2)
    node2.addleft(node3)

    node4 = BNode(cards[0])
    node5 = BNode(cards[1])

    node6 = BNode(cards[2])
    node7 = BNode(cards[3])

    node1.addleft(node4)
    node3.addleft(node5)

    node3.addright(node6)
    node2.addright(node7)

    if node1.evaluate() == 24:
        s.add(node1.display())



    #tree #5
    ## Add your code here
    node1 = BNode(ops[0])
    node2 = BNode(ops[1])
    node3 = BNode(ops[2])
    node1.addright(node2)
    node2.addright(node3)

    node4 = BNode(cards[0])
    node5 = BNode(cards[1])

    node6 = BNode(cards[2])
    node7 = BNode(cards[3])

    node1.addleft(node4)
    node2.addleft(node5)

    node3.addleft(node6)
    node3.addright(node7)

    if node1.evaluate() == 24:
        s.add(node1.display())




    return s

'''s = list(input())
if len(s) != 4:
    sys.exit()
for i in range(len(s)):
    if s[i] not in d.keys():
        sys.exit()
results = set()
s1 = [0, 1, 2, 3]
for L in list(itertools.permutations([0, 1, 2, 3], 4)):
    for i in range(4):
        s1[i] = s[L[i]]

    ops1 = [ops[0], ops[0], ops[0]]
    for i in range(len(ops)):
        for j in range(len(ops)):
            for k in range(len(ops)):
                ops1[0] = ops[i]
                ops1[1] = ops[j]
                ops1[2] = ops[k]
                results = results | evaluatefive(ops1, s1)
for result in results:
    print(result)
print(str(len(results)) + " solutions.")'''    
