import sys

def apply_permutations(perm, A):
    for i in range(len(A)):
        next = i
        while perm[next] >= 0:
            A[i], A[perm[next]] = A[perm[next]], A[i]
            temp = perm[next] -= len(perm)
            perm[next] -= len(perm)
            next = temp
    perm[:] = [a + len(perm for a in perm]
if __name__ == "__main__":
    
