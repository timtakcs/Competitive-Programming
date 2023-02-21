from heapq import *

class Union_Set:
    def __init__(self, n) -> None:
        self.link = [i for i in range(n)]
        self.size = [1 for i in range(n)]
    
    def find(self, x):
        while x != self.link[x]:
            x = self.link[x]
        
        return x

    def same(self, a, b):
        return self.find(a) == self.find(b)
    
    def unite(self, a, b):
        a = self.find(a)
        b = self.find(b)

        if self.size[a] < self.size[b]:
            temp = a
            a = b
            b = temp
        
        self.size[a] += self.size[b]
        self.link[b] = a

class Graph:
    def __init__(self, directed = True):
        self.adj = []
        self.directed = directed

    def add_node(self):
        self.adj.append([])
    
    def add_edge(self, u, v, w):
        self.adj[u].append((v, w))
        if self.directed:
            self.adj[v].append((u, w))

    ######################
    # Simple traversals
    ######################

    def bfs(self, u, v):
        vis = [False for i in range(len(self.adj))]
        q = []
        q.append(u)
        vis[u] = True

        while len(q):
            cur = q.pop(0)
            
            if cur == v:
                return True

            for n, w in self.adj[cur]:
                if not vis[n]:
                    q.append(n)
                    vis[n] = True
        
        return False

    def dfs(self, u, v, vis):
        vis[u] = True

        if u == v:
            return True

        for n, w in self.adj[u]:
            if not vis[n]:
                return self.dfs(n, v, vis)
            
    ######################
    # Shortest path
    ######################
    
    def dijkstra(self, u):
        vis = [False for i in range(len(self.adj))]
        dist = [999999 for i in range(len(self.adj))]
        vis[u] = True
        dist[u] = 0
        q = []
        heappush(q, ((0, u)))

        while(len(q)):
            cur_n = heappop(q)[1]

            if vis[cur_n]: continue
            vis[cur_n] = True

            for n, w in self.adj[cur_n]:
                if dist[cur_n] + w < dist[n]:
                    dist[n] = dist[cur_n] + w
                    heappush(q, (dist[n], n))

        return dist
    
    def floyd_warshall(self):
        dist = []

        n = len(self.adj)

        for i in range(n):
            dist.append([])
            for j in range(n):
                if i == j:
                    dist[i][j] = 0
                else:
                    dist[i][j] = 999999

        for i in range(n):
            for n, w in self.adj[i]:
                dist[i][n] = w
        
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j])

        return dist

    ######################
    # Min spanning tree
    ######################

    def kruskal(self):
        heap = []

        uset = Union_Set(len(self.adj))

        new_adj = [None for i in range(len(self.adj))]

        for v in range(len(self.adj)):
            for u, w in self.adj[v]:
                heappush(heap, (w, v, u))

        while len(heap):
            w, v, u = heappop(heap)

            if not uset.same(v, u):
                new_adj[v] = (u, w)
                uset.unite(v, u)
            else:
                continue
        
        return new_adj

        


