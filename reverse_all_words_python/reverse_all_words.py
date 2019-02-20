import sys

#byte array

def reverse_words (s):
    def reverse_range(s, start, end):
        while start < end:
            s[start], s[end] = s[end], s[start]
            start, end = start+1, end-1
    s.reverse()
    start = 0
    while True:
        end = s.find(b' ', start)
        if end < 0:
            break
        reverse_range(s, start, end)
        start = end + 1
    reverse_range(s, start, len(s) - 1)

if __name__ == "__main__":
    string = input().split(" ")
    inputWords = inputWords[-1::-1]
    #reverse_words(arr)
    print()
