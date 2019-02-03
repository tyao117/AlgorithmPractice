import sys
from collections import defaultdict
from collections import namedtuple

Edge = namedtuple('Edge', 'to weight')

def tpsortutil(u, graph, visited, stack, cur):
    # gets the order of it in reverse [last <- start]
    visited[u] = True
    cur.add(u)
    for i in graph[u]:
        if not visited[i.to]:
            tpsortutil(i.to, graph, visited, stack, cur)
        elif i in cur:
            return
    stack.append(u)

def maxpathUtil(graph, stack, dist):
    # gets the longest path and prints it out
    max_dist = 0
    while stack:
        u = stack.pop()
        max_dist = max(max_dist, dist[u])
        for v in graph[u]:
            dist[v.to] = max(dist[v.to], dist[u] + v.weight)
    print(max_dist)

def maxpath(graph, vertices):
    visited = [False] * vertices
    dist = [0] * vertices
    stack = []
    for i in range(vertices):
        cur = set()
        if not visited[i] and graph[i]:
            tpsortutil(i, graph, visited, stack, cur)
    del cur
    maxpathUtil(graph, stack, dist)

if __name__ == "__main__":
    vertices = int(input())
    graph = defaultdict(list)
    edges = int(input())
    for _ in range(edges):
        e = [int(x) for x in input().split()]
        t = Edge(to=e[1], weight=e[2])
        graph[e[0]].append(t)
    maxpath(graph, vertices)
