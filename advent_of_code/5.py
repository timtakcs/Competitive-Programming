with open("elves.in", "r") as f:
    stacks = []
    lines = f.readlines()

    for i in range((len(lines[0])) // 4):
        stacks.append([])

    idx = 0
    while lines[idx][1] != "1":
        line = lines[idx]
        ptr = 0
        
        for i in range(0, len(line), 4):
            stacks[ptr].append(line[i + 1])
            ptr += 1

        idx+=1

    for i in range(len(stacks)):
        stacks[i] = stacks[i][::-1]
        stacks[i] = list(filter((" ").__ne__, stacks[i]))

    for stack in stacks:
        print(stack)

    idx += 2

    nums = "0123456789"

    for i in range(idx, len(lines)):
        line = lines[idx]
        line = line.split()

        ops = []

        for each in line:
            if each[0] in nums:
                ops.append(int(each))

        idx += 1

        #part 1
        # for i in range(ops[0]):
        #     obj = stacks[ops[1] - 1].pop()
        #     stacks[ops[2] - 1].append(obj)
        
        #part 2
        to_move = stacks[ops[1] - 1][-ops[0]:]
        stacks[ops[1] - 1] = stacks[ops[1] - 1][:-ops[0]]
        stacks[ops[2] - 1] += to_move
        
    for stack in stacks:
        print(stack[-1], end='')
    print()