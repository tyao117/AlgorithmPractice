import sys
from collections import defaultdict
import heapq

def findwidestpath(adj_list, s, t, vertices):
    # initialize to negative
    dist = [-float('inf')] * vertices
    dist[s] = 0
    seen = set()
    pq = [(0,s)]
    seen.add(s)
    while pq:
        print(pq)
        w, u = heapq.heappop(pq)
        dist[u] = max(dist[u], -w)
        seen.add(u)
        print(dist)
        for v,w in adj_list[u]:
            if dist[v] < w and v not in seen:
                heapq.heappush(pq, (-w, v))
    print(dist)


if __name__ == "__main__":
    vertices = int(input())
    adj_list = [[] for i in range(vertices)]
    edges = int(input())
    for i in range(edges):
        u, v, w = [int(x) for x in input().split()]
        adj_list[u].append((v,w))
        adj_list[v].append((u,w))
    findwidestpath(adj_list, 0, 5, vertices)