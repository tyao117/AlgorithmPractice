import sys
from collections import defaultdict

def tpsortutil(u, visited, stack, cur):
    visited[u] = True
    for i in graph[u]:
        if not visited[i]:
            tpsortutil(i, visited, stack, cur)
        elif i in cur:
            return
    stack.append(u)

def topologicalsort(graph, vertices):
    visited = [False] * vertices
    stack = []
    for i in range(vertices):
        cur = set()
        if not visited[i] and graph[i]:
            tpsortutil(i, visited, stack, cur)
    del cur
    stack = stack[::-1]
    print(stack)

if __name__ == "__main__":
    vertices = int(input())
    graph = defaultdict(list)
    edges = int(input())
    for _ in range(edges):
        edge = [int(x) for x in input().split()]
        graph[edge[0]].append(edge[1])
    print(graph)
    topologicalsort(graph, vertices)