clear all; clc;
format long;

a = 0;
b = 1;
h = .5;
n = (b - a) / h;
y0 = 1;
t = a + [0 : n] * h;
y(1) = y0;
f = @(t, y) exp(t - y);

for i = 2 : n + 1
    y(i) = y(i - 1) + h / 2 * (f(t(i - 1), y(i - 1)) + f(t(i), y(i - 1) + h * f(t(i - 1), y(i - 1))));
end

y
yext = log(exp(t) + exp(1) - 1)
plot(t, y, '.', t, yext, '-*');