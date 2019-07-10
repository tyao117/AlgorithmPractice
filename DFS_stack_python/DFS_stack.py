import sys

def dfs_stack(graph, u):
    lst = [u]
    visited = set()
    while lst:
        top = lst.pop()
        if top not in visited:
            print(top)
            visited.add(top)
        for next in graph[top]:
            if next not in visited:
                lst.append(next)

if __name__ == "__main__":
    vertices = int(input())
    adj_list = [set() for i in range(vertices)]
    edges = int(input())
    for i in range(edges):
        u, v = [int(i) for i in input().split()]
        adj_list[u].add(v)
    dfs_stack(adj_list, 0)
