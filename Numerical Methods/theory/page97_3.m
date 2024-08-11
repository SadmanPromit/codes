x=0:.0001:6;
f=@(x) x.^3-9.*x.^2+23.*x-15;
a=f(x);
max=max(a)
min=min(a)