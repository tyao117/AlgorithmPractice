A = [1, 2, 3, 4, 5, 6]

def even_odd(lst):
    next_even, next_odd = 0, len(lst) - 1
    while next_even < next_odd:
        if (lst[next_even] % 2 == 0):
            next_even += 1
        else:
            lst[next_even], lst[next_odd] = A[next_odd], A[next_even]
            next_odd -= 1

even_odd(A)
print(A)

for i in range (5):
    print ("{} {}".format(i, ~i))