import sys

rows = 0
columns = 0
mydict = dict()
while True:
    try:
        name = raw_input()
        mylist = name.split()
        columns = len(mylist)
        print (mylist)
        for i in range (0,columns):
            mydict[i,rows] = mylist[i]
        rows = rows + 1
    except(EOFError):
        break
for i in range (0,columns):
    for j in range (0, rows):
        sys.stdout.write(mydict[i,j])
        sys.stdout.write(' ')
    sys.stdout.write('\n')
