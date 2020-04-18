office =[[5,-1,4],[6,3,-1],[2,-1,1]]
r = 1 
c = 0
move = ["go",'go','right','go','right','go','left','go']

def where_go(dx,dy,m):
    if dx==-1 and dy==0 :
        if m == "right":
            dx= 0
            dy= 1
        elif m == "left":
            dx = 0
            dy = -1
    elif dx==0 and dy ==1:
        if m == "right":
            dx= 1
            dy= 0
        elif m == "left":
            dx = -1
            dy = 0
    elif dx==1 and dy==0:
        if m == "right":
            dx= 0
            dy= -1
        elif m == "left":
            dx = 0
            dy = 1

    elif dx==0 and dy==-1:
        if m == "right":
            dx= -1
            dy= 0
        elif m == "left":
            dx = 1
            dy = 0
    
    return dx,dy

def solution(office, r, c, move):
    dx,dy = -1,0

    answer = office[r][c]
    office[r][c]=0
    
    R = len(office)

    for m in move:

        if m == "go":
            nr, nc = r+dx ,c + dy

            if nr<0 or nr >= R or nc <0 or nc >=R:
                continue
            if office[nr][nc] ==-1 :
                continue       
            
            answer = answer + office[nr][nc]
            r, c = nr,nc
            office[r][c] = 0
        else:
            dx,dy = where_go(dx,dy,m)
        
    return answer


print(solution(office,r,c,move))