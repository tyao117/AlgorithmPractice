#usr/bin/python
import sys

rows = 4
columns = 4
mydict = dict()
for i in range(0,4):
        name = raw_input()
        mylist = name.split()
        for j in range(0, len(mylist)):
            mydict[i,j] = mylist[j]
step = input()
for i in range (0,4):
    print '{} {} {} {}'.format(mydict[i,0], mydict[i,1], mydict[i,2], mydict[i,3])


