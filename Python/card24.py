# In card game 24, one needs to evaluate 4 cards to 24 using addition, subtraction,
# multiplication and division. Each of the 4 cards needs to be used once and only
# once. Note the cards J, Q, K, and A evaluate to 11, 12, 13 and 1 respectively.

# For example, the 4 cards J Q K and A can be evaluated to 24 as follows:
# A * (K - j) * Q, that is 1 * (13 - 11) * 12 = 24.

# Below we implement a class Check24, whose method is24() checks whether a postfix
# notation involving 4 cards and 3 operations evaluates to 24.

# Postfix notation is an unambiguous way of writing an arithmetic expression without
# parentheses. It is defined so that if “(exp1)op(exp2)” is a normal fully parenthesized
# expression whose operation is op, the postfix version of this is “pexp1 pexp2 op”,
# where pexp1 is the postfix version of exp1 and pexp2 is the postfix version of exp2.
# The postfix version of a single number or variable is just that number or variable.
# So, for example, the postfix version of “((5 + 2)∗(8 − 3))/4” is “5 2 + 8 3 −∗4 /”.

from fractions import Fraction
class ListStack:
    def __init__(self):
        self._L = []
        
    def push(self, item):
        self._L.append(item)

    def pop(self):
        return self._L.pop()

    def peek(self):
        return self._L[-1]

    def __len__(self):
        return len(self._L)

    def isempty(self):
        return len(self) == 0

class Check24:    
    ops = ['+', '-', '*', '/']
    d = {'A': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6' : 6, '7': 7, '8': 8, '9': 9, '0': 10, 'J': 11, 'Q': 12, 'K': 13}

    def is24(s):
        stack = ListStack()
        stack.push(Check24.d[s.pop(0)])
        stack.push(Check24.d[s.pop(0)])
        while len(s)> 0:
            ### Add your code below
            x = s.pop()
            if x.isdigit():
                stack.push(x)
            else:
                y1 = s.pop()
                y2 = s.pop()
                stack.push(str(eval(y2 + x + y1)))
        return stack.pop() == 24

exp = list('A2*3*4*')
print(Check24.is24(exp))

exp = list('8383/-/')
print(Check24.is24(exp))

exp = list('QKJ-*A/')
print(Check24.is24(exp))

exp = list('A357+*-')
print(Check24.is24(exp))
