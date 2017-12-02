def binarySearch(lst, item):
    if len(lst) == 0:
        return False
    else:
        midpoint = len(lst)//2
        if lst[midpoint] == item:
            return True
        else:
            if item < lst[midpoint]:
                return binarySearch(lst[:midpoint],item)
            else:
                return binarySearch(lst[midpoint+1:],item)

size = int(input().strip())
nums = input().split()
nums = [int(a) for a in nums]
print (nums)
print (binarySearch(nums,0))
print (binarySearch(nums,42))
