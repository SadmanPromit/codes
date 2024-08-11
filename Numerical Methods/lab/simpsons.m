clc; clear all; close all;
format long;

a = 0;
b = 2;
n = 8;
h = (b - a) / n;
c = 0;
d = 0;
f = @(x) (x^2*log(x^2+1));

for i = 1:n-1
    x(i) = a + i * h;
    if mod(i, 2) ~= 0
        d = d + 4 * f(x(i));
    else
        c = c + 2 * f(x(i));
    end    
end

simps = h / 3 * (f(a) + f(b) + c + d)