import re
txt = "I'm a stringy!"
def reverseWord(s):
    s = s[::-1]
    return s

lst = txt.split(' ')
for i in range(len(lst)):
    lst[i] = re.split("[A-Za-z]\w",lst[i])
    lst[i] = [x[::-1] for x in lst[i] if x.isalpha()]

print (' '.join(lst))