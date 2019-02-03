import sys
import random

def random_sampling(k, A):
    for i in range(k):
        r = random.randint(i, len(A) - 1)
        A[i], A[r] = A[r], A[i]
if __name__ == "__main__":
    A = [1, 2, 3, 4, 5]
    print(A)
    random_sampling(len(A), A)
    print(A)