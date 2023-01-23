import sys

stdin = input()
cards = stdin.split()

i = -1
sets = []

for card1 in range(0, (len(cards) - 2)):
    for card2 in range((card1 + 1), (len(cards) - 1)):
        for card3 in range((card2 + 1), (len(cards))):
            for a in range(0,(len(cards[card3]))):
                if ((cards[card1][a]) == (cards[card2][a]) == (cards[card3][a])):
                    i += 1
                elif ((int(cards[card1][a]) + int(cards[card2][a]) + int(cards[card3][a])) == 3):
                    i += 1
                else:
                    i = -1
                    pass
                if i == ((len(cards[card3])) - 1):
                    sets.append(card3)
                else:
                    pass
                if a == ((len(cards[card3])) - 1):
                    i = -1
                    pass
                elif i == -1:
                    pass

if sets == []:
    print(-1)
else:
    print(min(sets)+1)
