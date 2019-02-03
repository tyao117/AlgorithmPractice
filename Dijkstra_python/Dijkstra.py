import sys
from collections import defaultdict
import heapq

def findwidestpath(adj_list, s, t, vertices):
    dist = [sys.maxsize] * vertices
    parent = [None] * vertices
    print(dist)
    dist[s] = 0
    seen = set()
    pq = [(0, s)]
    # use Djikstra
    # replace D[u]+length(u->v) with
    #   min(D[u], length(u->v)) and
    #   max(D[v]) rather than min D[v]
    while pq:
        _, u = heapq.heappop(pq)
        for v, w in adj_list[u]:
            if (dist[v] > dist[u] + w):
                dist[v] = dist[u] + w
                heapq.heappush(pq,(w, v))
    print()
    print(dist)


if __name__ == "__main__":
    vertices = int(input())
    adj_list = [[] for i in range(vertices)]
    edges = int(input())
    for i in range(edges):
        u, v, w = [int(x) for x in input().split()]
        adj_list[u].append((v,w))
    print(adj_list)
    findwidestpath(adj_list, 0, 5, vertices)