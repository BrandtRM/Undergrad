def solvable(kstart, pawns):
    answr = []
    if pawns == set():
        return True
    moves = [(1,2), (-1,2), (1,-2), (-1,-2), (2,1), (2,-1), (-2,1), (-2,-1)]
    poss = [(kstart[0]+i[0], kstart[1]+i[1]) for i in moves]
    if any(x in poss for x in pawns):
        y = set(poss) & pawns
        for item in y:
            fake = set(pawns)
            z = {(item[0], item[1])}
            fake = fake - z
            answr.append(solvable(item, fake))
    return True in answr


def findstart(pawns):
    poss = []
    for x in range(1,9):
        for y in range(1,9):
            if solvable((x,y), pawns) == True:
                poss.append((x,y))
    if poss == []:
        return None
    else:
        poss = set(poss)
        answr = poss - pawns
        return answr
    
