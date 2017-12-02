#!/bin/python3

import sys

n = int(input().strip())
a = list(map(int, input().strip().split(' ')))
# Write Your Code Here
notSorted = True
times = 0
if (len (a) > 1):
    while (notSorted):
        notSorted = False
        for i in range (1,n):
            if (a[i]< a[i-1]):
                times += 1
                notSorted = True
                temp = a[i-1]
                a[i-1] = a[i]
                a[i] = temp
                break
        print (a)
print ("Array is sorted in", times, "swaps.")
print ("First Element:", a[0])
print ("Last Element:", a[n-1])
