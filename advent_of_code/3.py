def find_overlap(a, b, c):
    for char in a:
        if char in b and char in c:
            print(char)
            score = 0
            if char.upper() == char: score = ord(char) - 64 + 26
            else: score = ord(char) - 96
            return score

with open("elves.in", "r") as f:
    lines = f.readlines()
    sum = 0
    for i in range(0, len(lines), 3):
        lines[i], lines[i + 1], lines[i + 2] = lines[i].strip(), lines[i + 1].strip(), lines[i + 2].strip()
        sum += find_overlap(lines[i], lines[i + 1], lines[i + 2])

    print(sum)

