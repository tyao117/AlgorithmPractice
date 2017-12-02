# making a two list get in to one:
a = [1, 2 ,3, 5, 6, 8, 43, 64, 98]
b = [2, 4, 6 ,7, 8, 9, 43 , 45,]
def MergeList (a, b):
    i = j = 0
    lst = []
    while (i < len (a) and  j < len(b)):
        if (a[i] < b[j]):
            lst.append(a[i])
            i += 1
        elif (a[i] > b[j]):
            lst.append(b[j])
            j += 1
        else:
            lst.append(a[i])
            lst.append(b[j])
            i += 1
            j += 1
    while (i < len (a)):
        lst.append(a[i])
        i += 1
    while (j < len (b)):
        lst.append(b[j])
        j += 1
    return lst
x = MergeList(a,b)
print (x)