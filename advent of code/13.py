def compare(packet1, packet2):
    if isinstance(packet1, int) and isinstance(packet2, int):
        if packet1 > packet2:
            return -1;
        elif packet1 < packet2:
            return 1
        else:
            return 0
    elif isinstance(packet1, list) and isinstance(packet2, list):
        i = 0
        while i<len(packet1) and i<len(packet2):
            comparator = compare(packet1[i], packet2[i])
            if comparator == -1:
                return -1
            elif comparator == 1:
                return 1
            else:
                i += 1
        if i<len(packet1) and i == len(packet2):
            return -1
        elif i == len(packet1) and i < len(packet2):
            return 1
        else:
            return 0
    elif isinstance(packet1, list) and isinstance(packet2, int):
        return compare(packet1, [packet2])
    else:
        return compare([packet1], packet2)

with open("elves.in", "r") as f:
    inp = [line.split('\n') for line in f.read().split('\n\n')]
    inp[-1].pop()
    inp = [[eval(packet) for packet in pair] for pair in inp]

    sum = 0

    # part 1
    for i, input in enumerate(inp):
        if compare(input[0], input[1]) == 1:
            sum += i+1

    print(sum)

    # part 2
    packets = []
    for i in range(len(inp)):
        packets.append(inp[i][0])
        packets.append(inp[i][1])

    packets.append([[2]])
    packets.append([[6]])

    for i in range(len(packets)):
        for j in range(0, len(packets) - i - 1):
            if compare(packets[j], packets[j+1]) == -1:
                temp = packets[j]
                packets[j] = packets[j + 1]
                packets[j + 1] = temp
    
    two = 0
    six = 0
    for i, p in enumerate(packets):
        if p == [[6]]:
            six = i + 1
        if p == [[2]]:
            two = i + 1

    print(six * two)
