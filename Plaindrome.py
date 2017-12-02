def check_palin(word):
    for i in range(len(word)//2):
        if word[i] != word[-1*(i+1)]:
            return False
    return True

def all_palindromes(string):

    left,right = 0,len(string)
    j=right
    results=set()

    while left < right-1:
        temp = string[left:j] #Time complexity O(k)
        j-=1

        if check_palin(temp):
            results.add(temp)

        if j<left+2:
            left+=1
            j=right

    return list(results)

print (all_palindromes("racecarenterelephantmalayalam"))