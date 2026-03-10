txt="".join(b[2:]if len(b[2:])==7 else b[2:].zfill(7)for b in map(bin,map(ord,input())))
a=0
L=[]
for i in range(len(txt)-1):
 if txt[i]!=txt[i+1]:L.append(txt[a:i+1]);a=i+1
L.append(txt[a:])
print(*["0 "+"0"*len(e)if"1"in e else"00 "+"0"*len(e)for e in L],end="")
