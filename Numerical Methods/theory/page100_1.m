x=-5:.1:5;
y1=@(x) sqrt(4.*(1-x));
plot(x,y1(x),'r');
hold on;
y2=@(x) x.^2./4;
plot(x,y2(x),'b');
Area = quadl(@(x) sqrt(4.*(1-x)),-5,5)-quadl(@(x) (x.^2./4),-5,5)

a=real(y1(x));
b=real(y2(x));


x2 = [x, fliplr(x)];
inBetween = [a, fliplr(b)];
fill(x2, inBetween, 'g');