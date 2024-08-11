syms x;
int1=double(int(sin(x)/x,0,pi))
quadl1=quadl(@(x) sin(x)./x,0,pi)
int2=double(int(sqrt(1+(sin(x)^4)),0,pi))
quadl2=quadl(@(x) sqrt(1+(sin(x).^4)),0,pi)