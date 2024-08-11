%page90no2
x=-3:.0001:3;
g=x.*(exp(x)-x-1);
figure(1);
plot(x,g);
figure(2);
ezplot('g');
figure(3);
ezplot('g'); 
hold on;
ezplot('x^2+1');