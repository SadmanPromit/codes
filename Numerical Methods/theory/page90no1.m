%page90 no1
syms x
g=x*(exp(x)-x-1);
diffg=diff(g)
g1=subs(g,x,1)
diffg1=subs(diffg,x,1)
a1=@(t)subs(g,x,t);
a2=@(t)subs(diffg,x,t);
a1(1)
a2(1)