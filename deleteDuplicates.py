lst = [2, 3 , 5, 5 , 7 , 11, 11, 11, 13]

def delete_duplicates(lst):
    if not lst:
        return 0
    write_index = 1
    for i in range(1,len(lst)):
        if lst[write_index -1] != lst[i]:
            lst[write_index] = lst[i]
            write_index += 1
    while (write_index < len(lst)):
        lst.pop()
    return write_index

delete_duplicates(lst)
print (lst)