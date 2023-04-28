def print_display(display):
    for row in display:
        for col in row:
            print(col, end='')
        print()

with open("elves.in", "r") as f:
    lines = f.readlines()

    for i in range(len(lines)):
        lines[i] = lines[i].strip()
        lines[i] = lines[i].split(" -> ")
        for j in range(len(lines[i])):
            lines[i][j] = eval("[" + lines[i][j] + "]")

    display = []

    minx = 9999
    maxy = 0
    maxx = 0

    for i in range(len(lines)):
        for j in range(len(lines[i])):
            minx = min(minx, lines[i][j][0])
            maxy = max(maxy, lines[i][j][1])

    for i in range(len(lines)):
        for j in range(len(lines[i])):
            lines[i][j][0] -= minx

    for i in range(len(lines)):
        for j in range(len(lines[i])):
            maxx = max(maxx, lines[i][j][0])

    for i in range(maxy):
        display.append([])
        for j in range(maxx):
            display[i].append(".")

    for i in range(len(lines)):
        for j in range(len(lines) - 1):
            x = lines[i][j][0] - 1
            y = lines[i][j][1] - 1
            x_final = lines[i][j+1][0] - 1
            y_final = lines[i][j+1][1] - 1

            if x < x_final:
                while x < x_final:
                    display[x][y] = "#"
                    x += 1

            elif x > x_final:
                while x > x_final:
                    print(x, x_final)
                    display[x][y] = "#"
                    x -= 1

            if y < y_final:
                while y < y_final:
                    display[x][y] = "#"
                    y += 1

            elif y > y_final:
                while y > y_final:
                    display[x][y] = "#"
                    y -= 1


    print_display(display)


    