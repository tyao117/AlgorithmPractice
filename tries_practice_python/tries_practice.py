import sys

def getTries(words):
    # make the trie
    trie = {}
    for w in words:
        t = trie
        for c in w:
            if c not in t:
                t[c] = {}
            t = t[c]
        t['#'] = '#'
    print(trie)
    
if __name__ == "__main__":
    size = int(input())
    words = []
    for i in range(size):
        words.append(input())
    getTries(words)