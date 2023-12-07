with open("elves.in", "r") as f:
    # lines = f.readlines()
    # count = 0

    # for line in lines:
    #     line = line.strip()
    #     line = line.split(",")

    #     line[0] = line[0].split("-")
    #     line[1] = line[1].split("-")

    #     start1, end1 = int(line[0][0]), int(line[0][1])
    #     start2, end2 = int(line[1][0]), int(line[1][1])

    #     if (start1 <= start2 and end2 <= end1) or (start2 <= start1 and end1 <= end2):
    #         count += 1
    
    # print(count)

    #part 2

    lines = f.readlines()
    count = 0

    sections = []

    for line in lines:
        line = line.strip()
        line = line.split(",")

        line[0] = line[0].split("-")
        line[1] = line[1].split("-")

        start1, end1 = int(line[0][0]), int(line[0][1])
        start2, end2 = int(line[1][0]), int(line[1][1])

        if start1 in range(start2, end2 + 1) or start2 in range(start1, end1 + 1):
            count += 1
        elif end1 in range(start2, end2 + 1) or end2 in range(start1, end1 + 1):
            count += 1
        
    print(count)
            



