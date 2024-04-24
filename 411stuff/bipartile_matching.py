newchefs = [[False for i in range(4 * z)] for j in range(y)]

for i in range(z):
    for j in range(y):
        for k in range(4):
            newchefs[4 * i + k][j] = chefs[i][j]

chefs = newchefs

adj = {}

adj[s] = []

for i in range(x):
    