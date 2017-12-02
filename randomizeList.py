import random
array = [1,2,3,4,5,6,7,8,9]
def randomizeList(lst):
    b = len(lst) -1
    for d in range(b,0,-1):
        e = random.randint(0,d)
        if e == d:
            continue
        lst[d], lst[e] = lst[e], lst[d]
    

randomizeList(array)
print(array)