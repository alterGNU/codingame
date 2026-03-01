if input()=="0":input(0)
t=[*map(int,input().split())]
print(sorted([x for x  in t if abs(x)==min(map(abs,t))])[-1])
