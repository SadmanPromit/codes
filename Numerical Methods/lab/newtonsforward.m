clear all
close all
clc
format long

x = [1891 1901 1911 1931];
f = [46 66 81 93 101];
h = x(2) - x(1);
!p = 1935;

for i = 1 : (length(f) - 1)
    Df(i) = f(i + 1) - f(i);
end
for i = 1 : (length(Df) - 1)
    D2f(i) = Df(i + 1) - Df(i);
end
for i = 1 : (length(D2f) - 1)
    D3f(i) = D2f(i + 1) - D2f(i);
end
for i = 1 : (length(D3f) - 1)
    D4f(i) = D3f(i + 1) - D3f(i);
end
k = (p - x(1)) / h;
Forward_Interpolation = f(1) + k * Df(1) + ((k * (k - 1)) / 2) * D2f(1) + ((k * (k - 1) * (k - 2)) / 6) * D3f(1) + ((k * (k - 1) * (k - 2) * (k - 3)) / 24) * D4f(1)