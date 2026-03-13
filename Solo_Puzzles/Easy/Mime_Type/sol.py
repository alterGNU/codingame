import sys
n,_,*l=open(0)
D={}
for ind,i in enumerate(l):
    if ind<int(n):
        a,b=i.split()
        D[a.lower()]=b
    else:
        res="UNKNOWN"
        if"."in i :
            ext=i[i.rindex(".")+1:-1].lower()
            if ext in D:
                res=D[ext]
        print(res)
