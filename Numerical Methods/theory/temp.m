clc; clear all; close all;
format long;

a = 0;
b = 1;
n = 9;
h = (b - a) / n;
c = 0;
f = @(x) (1/(1+x));

for i = 1:n-1
    x(i) = a + i * h;
    c = c + 2 * f(x(i));
end

trape = h / 2 * (f(a) + f(b) + c)