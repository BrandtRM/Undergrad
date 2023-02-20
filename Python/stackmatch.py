### You are given a string of parentheses (“(“, “)”), braces(“{“, “}”)
### and brackets(“[“, “]”). You need to check whether each “(”, “{”, or “[”
### is paired with a matching “)”, “}”, or “[”.
### For example, “( )(( )){([( )])}” and “()( )(( )){([( )])}” are matched
### correctly. While “)(( )){([( )])}”, “({[ ])}” and “(“ are not matched
### correctly. Write code to test whether such a string is matched correctly.
### Complete the code for the method def match(exp).

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

def match(exp):
    d = {'(':')', '{':'}', '[':']'}
    L = list(exp)
    stack = ListStack()
    for c in L:
        ## Fill in your code here
        if L.count('(') == L.count(')'):
            return True
        elif L.count('[') == L.count(']'):
            return True
        elif L.count('{') == L.count('}'):
            return True
        else:
            return False
    return stack.isempty()

exp = '( )(( )){([( )])}'
print(exp)
print(match(exp))

exp = '( )(( )){([( )])})'
print(exp)
print(match(exp))


exp = '( [)(( )){([( )])})'
print(exp)
print(match(exp))

exp = ''
print(exp)
print(match(exp))
    
