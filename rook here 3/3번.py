# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    aaa = "aaa"
    
    result = S.find(aaa)
    
    if result == 1:
        return -1
    
    else:
        no_a = 0
        yes_a = 0
        for alpa in S:
            if alpa != 'a':
                no_a+=1
            else:
                yes_a+=1
        
        total_a = (no_a+1)*2
        return total_a -yes_a