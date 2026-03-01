a,*L,b=[input()for _ in"*"*int(input().split()[1])]
A,I,B=map(str.split,[a,a,b])
for l in L:
    for j,x in enumerate(zip(A[:-1],A[1:])):
        if [*l][j*3+1]=="-":A[A.index(x[0]):A.index(x[1])+1]=A[A.index(x[0]):A.index(x[1])+1][::-1]
for i in I:print(i+B[A.index(i)])
