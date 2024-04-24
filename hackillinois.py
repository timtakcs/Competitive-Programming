import requests

jwt = {"Authorization":"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6ImdpdGh1YjczNDgxNjk4IiwiZW1haWwiOm51bGwsInByb3ZpZGVyIjoiZ2l0aHViIiwicm9sZXMiOlsiVVNFUiJdLCJleHAiOjE3MDk0ODc5MjcuOTE5LCJpYXQiOjE3MDY4OTU5Mjd9.T03WfiQU--2jjkl3wXYJw-PpAw-M7mfUbLOy4xpx7N4"}
url = 'https://artemis.hackillinois.org/challenge'
headers = {'Authorization': jwt['Authorization'], 'Content-Type': 'application/json'}

inp = requests.get(url, headers=headers)

data = inp.json()

adj = {}
vertices = []
goodness = data['wizards']

for a, b in data['alliances']:
    if a not in adj:
        adj[a] = []
        vertices.append(a)
    if b not in adj:
        adj[b] = []
        vertices.append(b)
    
    adj[a].append(b)
    adj[b].append(a)

def bfs(adj, vertices):
    vis = {}

    for v in vertices:
        vis[v] = False

    totals = []

    for v in vertices:
        if not vis[v]:
            ans = 0;
            q = []
            q.append(v)
            while len(q):
                cur = q.pop(0)
                vis[cur] = True
                ans += goodness[cur]

                for u in adj[cur]:
                    if not vis[u]:
                        q.append(u)
            totals.append(ans)

    return max(totals)

ans = bfs(adj, vertices)

body = {
    "max_goodness":ans
}
