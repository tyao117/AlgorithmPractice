string = "abcabbbbaaacccdd"

def concatenateStr(s):
    lst = []
    curr_char = s[0]
    counter = 1
    for i in range(1, len(s)):
        if s[i] != curr_char:
            lst.append(curr_char)
            curr_char = s[i]
            if counter > 1:
                lst.append(str(counter))
                counter = 1
        else:
            counter += 1
    if (lst[-1] == curr_char):
        lst.append(str(counter))
    else:
        lst.append(curr_char)
    # need to work on the ending of the string
    return ''.join(lst)

print (concatenateStr(string))