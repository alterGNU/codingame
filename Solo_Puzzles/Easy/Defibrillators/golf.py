from math import pi as PI, cos as COS
c=lambda x:float(x.replace(",","."))
r=lambda x:x*PI/180
d=lambda xa,ya,xb,yb:6371*(((xb-xa)*COS((ya+yb)/2))**2+(yb-ya)**2)**.5
lo,la=map(r,map(c,[input(),input()]))
D=F=None
for _ in range(int(input())):
 _,n,_,_,x,y=input().split(";")
 nd=d(lo,la,r(c(x)),r(c(y)))
 if D==None or D>nd:D,F=nd,n
print(F)
