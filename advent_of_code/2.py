def get_win(a, b, things, things2):
    idx1 = things.index(a)
    idx2 = things2.index(b)

    if idx2 == idx2: return 3

    idx2 = (idx2 + 1)%3

    if idx2 == idx1: return 0

    idx2 = (idx2 + 1)%3

    if idx2 == idx1: return 6
    

with open("elves.in", "r") as f:
    lines = f.readlines()

    sum = 0
    vals = {'A': 1, 'X': 1, 'B': 2, 'Y': 2, 'C': 3, 'Z': 3}
    things = ['A', 'B', 'C']
    things2 = ['X', 'Y', 'Z']

    outcomes = {
        "AX":4, "AY":8, "AZ":3, 
        "BX":1, "BY":5, "BZ":9, 
        "CX":7, "CY":2, "CZ":6 
    }

    new_outcomes = {
        "AX":3, "AY":4, "AZ":8, 
        "BX":1, "BY":5, "BZ":9, 
        "CX":2, "CY":6, "CZ":7 
    }

    for line in lines:
        line = line.strip()
        line = line[0] + line[2]
        print(line)
        sum += new_outcomes[line]
    
    print(sum)