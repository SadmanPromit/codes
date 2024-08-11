function [ans1,ans2] = cosxf(x,n)
%page82 no2
ans1=cosx(x,n)
x=pi/12;
n = 1;
ans2=cosx(x,n)
n=4;
ans3=cosx(x,n)
n=10;
ans4=cosx(x,n)
end
function cosx=cosx(x,n)
cosx=0;
for i=0:n
    cosx=cosx+((-1)^i*x^(2*i))/factorial(2*i);
end
end