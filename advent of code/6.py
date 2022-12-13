with open("elves.in", "r") as f:
    lines = f.readlines()
    lines = lines[0]

    for i in range(len(lines) - 14):
        sub = lines[i:i+14]
        if len(set(sub)) == len(sub):
            print(i + 14)
            break