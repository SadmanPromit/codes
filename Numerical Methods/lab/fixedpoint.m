clc
clear all

x=.5;
Es=1e-4;
Ea=Es+1;
i=0;

while Ea > Es
    xold=x
    x = 1/(sqrt(x+1));
    Ea = abs((x-xold)/x)*100;
    i = i+1;
end

x  %the root
i  %number of iterations