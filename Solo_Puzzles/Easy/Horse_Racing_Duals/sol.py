C=sorted([*map(int,open(0))][1:])
res=C[1]-C[0]
for i in range(1,len(C)-1):
    diff = C[i+1]-C[i]
    if diff<res:
        res=diff
print(res)
