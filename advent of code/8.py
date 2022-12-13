def is_visible(i, j, height, forest):
    count = 0
    y=j-1
    count1 = 0
    while y >= 0:
        if forest[i][y] >= height:
            count1 += 1
            break
        count1 += 1
        y -= 1
    
    y=j+1
    count2 = 0
    while y < len(forest):
        if forest[i][y] >= height:
            count2 += 1
            break
        count2 += 1
        y+=1
    
    x=i-1
    count3 = 0
    while x >= 0:
        if forest[x][j] >= height:
            count3 += 1
            break
        count3 += 1
        x -= 1

    x=i+1
    count4 = 0
    while x < len(forest[0]):
        if forest[x][j] >= height:
            count4 += 1
            break
        count4 += 1
        x += 1

    print(count1, count2, count3, count4)
    
    return count1 * count2 * count3 * count4
    # if count == 4: return False
    # else: return True

with open("elves.in", "r") as f:
    lines = f.readlines()
    forest = []

    for i in range(len(lines)):
        forest.append([])
        lines[i] = lines[i].strip()
        for num in lines[i]:
            forest[i].append(int(num))

    visibles = 0
    mx = 0

    for i in range(len(forest)):
        for j in range(len(forest[i])):
            # if is_visible(i, j, forest[i][j], forest):
            #     visibles += 1
            mx = max(mx, is_visible(i, j, forest[i][j], forest))

    print(mx)