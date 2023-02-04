class Pattern:
    
    def __init__(self, pattern, wildcard = None):
        self.pattern = pattern
        self.wildcard = wildcard

    def matches(self, text):
        pattern = self.pattern
        wildcard = self.wildcard
        x = 0
        index = -1
        while x < (len(text)):
            index = x
            for y in range (len(self.pattern)):
                if text[x + y] != self.pattern[y] and self.wildcard != self.pattern[y]:
                    index = -1
                    break
            if index != -1:
                return index
            x = x + 1
        return index
    
    def setwildcard(self, wildcard):
        self.wildcard = wildcard
