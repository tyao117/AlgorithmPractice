import sys

def find(arr, x):
    if arr[x] != x:
        arr[x] = find(arr, arr[x])
    return arr[x]

def union(arr, i, j):
    pi, pj = find(arr, i), find(arr, j)
    if pi != pj:
        arr[pi] = pj

def connected(arr, i, j):
    return find(arr, i) == find(arr, j)

if __name__ == "__main__":
    vertices = int(input())
    arr = [int(i) for i in range(vertices)]
    connections = int(input())
    edges = []
    for i in range(connections):
        edges.append(tuple(int(x) for x in input().split()))
    print(edges)
    edges = sorted(edges)
    print(edges)
    # running through the connections
    for i in range(vertices):
        print(i, " is connected to", find(arr, i))