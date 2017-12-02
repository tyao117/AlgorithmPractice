stringToSolve = input()

def palindrome_solver(s):
    # if it finds nothing, return ""
    found = set()
    for idx, char in enumerate (s):
        
        #check for odd sized palindrome
        start, end = idx -1, idx +1
        while (start >= 0 and end < len (s) and s[start] == s[end]):
            found.add(s[start:end+1])
            start -=1
            end += 1
        
        #check for the even sized palindrome:
        start, end = idx -1, idx     
        while (start >= 0 and end < len(s) and s[start] == s[end]):
            found.add(s[start:end+1]) 
            start -= 1
            end += 1
    return found
                                 
                   

setOfPalindromes = palindrome_solver(stringToSolve)
print (list(setOfPalindromes))