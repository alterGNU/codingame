L=sorted([*map(int,open(0))][1:])
print(sorted([b-a for a,b in zip(L[:-1],L[1:])])[0])
