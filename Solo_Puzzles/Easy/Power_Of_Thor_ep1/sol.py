tx, ty, x, y = map(int,input().split())
while 1:
    int(input())# The remaining amount of turns Thor can move.
    res=""
    if y > ty:
        res += "N"
        ty+=1
    if y < ty:
        res += "S"
        ty-=1
    if x > tx:
        res += "W"
        tx+=1
    if x < tx:
        res += "E"
        tx-=1
    print(res
