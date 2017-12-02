a = 8 
b = 2

def power (a,b):
    result, power = 1.0, b
    if b < 0:
        power, a = -power, 1.0 / a
    while power:
        if power & 1:
            result *= a
        a, power = a * a, power >> 1
    return result

print (power(8,2))