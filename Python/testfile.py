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
        if self.left == None and self.right == None:
            return d[self.data]
        leftsum = evaluate(self.left)
        rightsum = evaluate(self.right)
        if self.element in ops:
            if self.element == '+':
                return (leftsum + rightsum)
            if self.element == '-':
                return (leftsum - rightsum)
            if self.element == '*':
                return (leftsum * rightsum)
            if self.element == '/':
                return (leftsum / rightsum)
            

node1 = BNode('*')

node2 = BNode('*')
node3 = BNode('A')
node1.addleft(node2)
node1.addright(node3)

node4 = BNode('-')
node5 = BNode('Q')

node6 = BNode('K')
node7 = BNode('J')

node2.addleft(node4)
node2.addright(node5)

node4.addleft(node6)
node4.addright(node7)
print(BNode.evaluate(1))
#self.assertEqual(node1.evaluate(), 24)
#self.assertEqual(node1.display(), '(((13-11)*12)*1)')
