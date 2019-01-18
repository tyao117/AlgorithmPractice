import sys

def dfsutil(u, adj_list, toFind, visited, ans):
    visited[u] = True
    found = False
    print(u)
    if u == toFind or u in ans:
        return True
    for v in adj_list[u]:
        if not visited[v]:
            if dfsutil(v, adj_list, toFind, visited, ans):
                found = True
    return True if found else False

def dfs(adj_list, toFind, vertices):
    original = [False for i in range(vertices)]
    original[toFind] = True
    ans = set()
    ans.add(toFind)
    for x in range(vertices):
        copylst = list(original)
        copylst[toFind] = False
        if not original[x]:
            if dfsutil(x, adj_list, toFind, copylst, ans):
                ans.add(x)
            print()
        
    print(len(ans) == vertices)

if __name__ == "__main__":
    vertices = int(input())
    edges = int(input())
    adj_list = [set() for _ in range(vertices)]
    for _ in range(edges):
        edge = [int(x) for x in input().split()]
        adj_list[edge[0]].add(edge[1])
    toFind = int(input())
    dfs(adj_list, toFind, vertices)
