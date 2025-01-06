from collections import defaultdict

def solve(s1, s2):
    chars = defaultdict(int)
    
    for ch in s1:
        chars[ch] += 1
        
    for ch in s2:
        chars[ch] -= 1
    
    for value in chars.values():
        if value != 0:
            return False
            
    return True
