w = int(input())
h = int(input())
m = [[*input().replace(".","0")]for i in range(h)]
for i,l in enumerate(m):
    for j,v in enumerate(l):
        if v=="x":
            for a in range(max(0,i-1),min(i+2,h)):
                for b in range(max(j-1,0), min(j+2,w)):
                    if a==i and b==j:
                        m[a][b]="."
                    else:
                        try:
                            m[a][b]=str(int(m[a][b])+1)
                        except:
                            pass
for l in m:print("".join(l).replace("0","."))
