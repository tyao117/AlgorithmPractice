import random
array = [random.randint(0,50) for i in range (9) ]
print (array)
def quickSort(arr):
    if len(arr) < 1:
        return arr
    pivot_index = random.randint(0, len(arr) - 1)
    left = []
    mid = [arr[pivot_index]]
    right = []
    for i in range(len(arr)):
        if i != pivot_index:
            if arr[pivot_index] > arr[i]:
                left.append(arr[i])
            elif arr[pivot_index] < arr[i]:
                right.append(arr[i])
            else:
                mid.append(arr[i])
    return quickSort(left) + mid + quickSort(right)

print (quickSort(array))