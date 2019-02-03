import sys

def remove_duplicates(string):
    if not string or len(string) == 1:
        return string
    m = {}
    for i in range(len(string)):
        m[string[i]] = i
    begin, end = 0, min(m.values())
    res_str = []
    while m:
        minChar = chr(ord('z') + 1)
        for j in range(begin, end+1):
            if string[j] < minChar and string[j] in m:
                minChar = string[j]
                begin = j + 1
        res_str.append(minChar)
        del(m[minChar])
        if string[end] == minChar:
            if m:
                end = min(m.values())
    return "".join(res_str)


if __name__ == "__main__":
    string = input()
    print(remove_duplicates(string))
