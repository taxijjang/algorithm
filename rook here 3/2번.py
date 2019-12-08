# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(message, K):
    word = message.split()
    res =""
    cnt =0
    word_len = 0
    for w_cnt , w in enumerate(word):
        word_len += len(w)
        cnt = word_len + w_cnt
        
        if cnt <= K:
            res += w
        
        else:
            break
    
        res += " "
    res = res[:-1]
    return res