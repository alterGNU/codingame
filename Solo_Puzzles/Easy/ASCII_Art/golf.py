l=int(input())
h=int(input())
t=input().upper()
M=[input()for _ in'*'*h]
F=[""for _ in"*"*h]
for i in t:
 x=(26,ord(i)-ord("A"))[i.isalpha()]
 for j,m in enumerate(M):F[j]+=m[l*x:l*x+l]
for f in F:print(f)
