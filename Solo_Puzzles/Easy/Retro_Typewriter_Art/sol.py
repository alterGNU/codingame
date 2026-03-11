d = {"sp":" ","bS":"\\","sQ":"'","nl":"\n"}
def F(a):
    if all(e.isdigit()for e in a):
        return int(a[:-1])*a[-1]
    j=0
    for i,e in enumerate(a):
        if not(e.isdigit()):
            j=i
            break
    x,y=int(a[:j]),a[j:]
    if y in d.keys():return d[y]*x
    else:return x*y
for T in input().split("nl"):
    for t in T.split():
        print(F(t),end="")
    print()
