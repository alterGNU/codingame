I=input
is_a_palindrom=lambda w:w==w[::-1]
search_del_add=lambda w:any(is_a_palindrom(w[:i]+w[i+1:])for i in range(len(w)))
search_replace=lambda w:sum(w[i]!=w[-i-1]for i in range(len(w)//2))<2
I(''.join(["0","1"][search_del_add(w)+search_replace(w)>0]for w in[I()for _ in"*"*int(I())]))
