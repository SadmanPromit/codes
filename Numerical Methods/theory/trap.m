function err01 = nuint011(a, b, n)
% here we implement trapezoidal rule for different choices of n
h = (b-a)/n;
x = a + [0:n]*h;
f=func(x);

trap01 = (.5*h) * ((f(1) + f(end)) + 2 * sum(f(2:end - 1)));

ext = 1/pi;

err01 = abs(trap01 - ext);
end