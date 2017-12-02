text = "-123"

def string_to_int(s):
    nums = "1234567890"
    partial_sum = 0
    begin = False
    is_negative = False
    for i in range(len(s)):
        print (s[i])
        if (i == 0 and s[i] == '-'):
            is_negative = True
        if (nums.find(s[i]) != -1):
            if begin:
                partial_sum = partial_sum * 10 + int(s[i])
            else:
                partial_sum += int(s[i])
                begin = True
        print(partial_sum)
    if is_negative:
        partial_sum = -partial_sum
    return partial_sum

print (string_to_int(text))

def int_to_string(x):
    is_negative = False
    # not dealing with the negative sign
    if x < 0:
        x, is_negative = -x, True
    s = []
    while True:
        s.append(chr(ord('0')+ x % 10))
        x //= 10
        if x == 0:
            break
    # adds the negative
    return ('-' if is_negative else '') + ''.join(reversed(s))

print (type(int_to_string(123)))

