# first number is the sum and second number is the abs

def beatTheSpread(arr):
    sumVal = arr[0]
    absVal = arr[1]
    res = []
    a = int((sumVal+absVal) / 2)
    b = a - absVal
    if a*2 == sumVal+absVal and b > 0:
        res.append(a)
        res.append(b)
    return res

if __name__ == "__main__":
    test_cases = int(input())
    for i in range(test_cases):
        nums = [int(x) for x in input().split()]
        res = beatTheSpread(nums)
        if res:
            for i in res:
                print(i, end=" ")
            print()
        else:
            print("impossible")