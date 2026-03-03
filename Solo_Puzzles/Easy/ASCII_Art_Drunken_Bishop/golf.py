M=[[0 for _ in"*"*17]for _ in"*"*9]
X,Y=4,8
F=[x[i:i+2]for x in[format(int(x,16),"08b")for x in input().split(":")]for i in range(6,-1,-2)]
for a,b in F:
 X=min(max(0,X+(-1,1)[a=="1"]),8)
 Y=min(max(0,Y+(-1,1)[b=="1"]),16)
 M[X][Y]+=1
print(f"+{'-'*3}[CODINGAME]{'-'*3}+")
for i,m in enumerate(M):print("|"+"".join(((" .o+=*BOX@%&#/^"[e%15],'E')[(i,j)==(X,Y)],'S')[(i,j)==(4,8)]for j,e in enumerate(m))+"|")
print(f"+{'-'*17}+")
