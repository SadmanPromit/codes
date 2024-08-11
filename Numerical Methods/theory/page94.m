x=-1:.5:1;
fe = x.^5 + 3.*x.^4 -3.*x + 7;
plot(x,fe);
clear all;
syms x;
f=x^5+3*x^4-3*x+7;
derivative=diff(f)
xcr=double(solve(derivative));
xcr(imag(xcr) > eps, :) = [];
xcr = real(xcr)
minima = fminbnd(@(x) x^5+3*x^4-3*x+7,-1,1)
maxima = fminbnd(@(x) -(x^5+3*x^4-3*x+7),-1,1)