T=[input().split()for i in range(int(input()))]
f=lambda a,b,c:[[int(b)+int(c),int(b)-int(c),int(b)*int(c)][("A","S","M").index(a[0])]if a[0]!="V"else b]
i=0
while any(len(e)!=1 for e in T):
    F=False
    ind=i%len(T)
    if len(T[ind])!=1:
        a,b,c=T[ind]
        if"$"in b:
            if len(T[int(b[1:])])==1:b=T[int(b[1:])][0]
            else:F=True
        if"$"in c:
            if len(T[int(c[1:])])==1:c=T[int(c[1:])][0]
            else:F=True
        if not(F):T=T[:ind]+[f(a,b,c)]+T[ind+1:]
    i+=1
for t in T:print(t[0])      
