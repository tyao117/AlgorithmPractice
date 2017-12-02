#array to binTree
array = [1 ,2, 3, 4, 5, 6, 7]

class Node:
    def __init__(self, x):
        self.value = x
        self.left = None
        self.right = None

def BinarySort(arr):
    root = None
    def binarySearch(arr, start, end):
        if start > end:
            return None
        mid = (start + end) // 2
        root = Node (arr[mid])
        root.left = binarySearch(arr, start, mid - 1)
        root.right = binarySearch(arr, mid + 1, end)
        return root
    root = binarySearch(arr, 0, len(arr) -1 )
    return root

root = BinarySort(array)

def Inorder(x):
    if x is not None:
        Inorder(x.left)
        print(x.value)
        Inorder(x.right)

Inorder(root)
