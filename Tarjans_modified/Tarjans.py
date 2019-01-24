import sys

def SCCUtil(u, low_key, number, stackMember, st, index, graph, toFind):
    number[u] = index
    low_key[u] = index
    index += 1
    stackMember[u] = True
    st.append(u)
    for v in graph[u]:
        if number[v] == -1:
            SCCUtil(v, low_key, number, stackMember, st, index, graph, toFind)
            low_key[u] = min(low_key[u], low_key[v])
        elif stackMember[v] == True:
            low_key[u] = min(low_key[u], number[v])
    w = -1
    res = []
    isFound = False
    if low_key[u] == number[u]:
        while w != u:
            w = st.pop()
            if toFind == w:
                isFound = True
            res.append(w)
            stackMember[w] = False
        print(res)
        
def SCC(size, graph, toFind):
    number = [-1] * size
    low_key = [-1] * size
    stackMember = [False] * size
    st = []
    index = 0
    for i in range(size):
        if number[i] == -1:
            SCCUtil(i, low_key, number, stackMember, st, index, graph, toFind)

if __name__ == "__main__":
    vertices = int(input())
    edges = int(input())
    adj_list = [set() for _ in range(vertices)]
    for _ in range(edges):
        edge = [int(x) for x in input().split()]
        adj_list[edge[0]].add(edge[1])
    toFind = int(input())
    print(adj_list)
    print("ToFind =", toFind)
    SCC(vertices, adj_list, toFind)