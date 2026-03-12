e=enumerate
L=[*open(0)]
t=[abs(int(L[0])-x-abs(y-L[-1].index("^")))for x,l in e(L[1:-1])for y,c in e(l[:-1])if(c!=".")]
for i in range(max(t)+1):print("SHOOT"if i in t else"WAIT")
