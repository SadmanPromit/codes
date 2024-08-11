clc; clear all; close all;
format long;

a = 0;
b = 2;
n = 8;
h = (b - a) / n;
c = 0;
f = @(x) (x^2*exp(-x^2));

for i = 1:n-1
    x(i) = a + i * h;
    c = c + 2 * f(x(i));
end

trape = h / 2 * (f(a) + f(b) + c)