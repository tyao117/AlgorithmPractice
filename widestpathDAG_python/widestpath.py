import sys
from collections import defaultdict
import heapq

def findwidestpath(adj_list, s, t, vertices):
    # initialize to negative
    dist = [-float('inf')] * vertices
    dist[s] = 0
    pq = [(0, s)]
    parent = [None] * vertices
    while pq:
        _, u = heapq.heappop(pq)
        for v, w in adj_list[u]:
            # if the current dist is less than previous then we can add more
            if dist[v] < max(dist[u], w):
                # still get the minimum bottle neck
                dist[v] = min(dist[u], w) if dist[u] else w
                parent[v] = u
                # implement a max heap
                heapq.heappush(pq,(-w, v))
    print(parent)
    print(dist[t])


if __name__ == "__main__":
    vertices = int(input())
    adj_list = [[] for i in range(vertices)]
    edges = int(input())
    for i in range(edges):
        u, v, w = [int(x) for x in input().split()]
        adj_list[u].append((v,w))
    print(adj_list)
    findwidestpath(adj_list, 0, 5, vertices)