n=int(input())
m=int(input())
d={a:b for a,b in[input().split()for _ in"*"*n]}
for i in range(m):
    x,y,a,b = input().split()
    z=""
    if y=="AND":
        for j,k in zip(d[a],d[b]):z+=("_","-")[j==k=="-"]
    if y=="OR":
        for j,k in zip(d[a],d[b]):z+=("_","-")["-"in(j,k)]
    if y=="XOR":
        for j,k in zip(d[a],d[b]):z+=("_","-")[j+k in"-_ _-"]
    if y=="NAND":
        for j,k in zip(d[a],d[b]):z+=("-","_")[j==k=="-"]
    if y=="NOR":
        for j,k in zip(d[a],d[b]):z+=("-","_")["-"in(j,k)]
    if y=="NXOR":
        for j,k in zip(d[a],d[b]):z+=("-","_")[j+k in"-_ _-"]
    print(x,z)
