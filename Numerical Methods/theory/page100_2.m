inti1=double(quadl(@(x) exp(-x.^2),-2,2));
fprintf('%.10f',inti1);
x=-2:.1:2;
N=length(x);
f=exp(-x.^2);
plot(x,f);
f=@(x) exp(-x^2);
x0 = -2;
xN = 2;
h = (xN-x0)/N;
sum=0;
for i=1:N-1
    sum=sum+f(xN);
end
inti2=(h/2).*f(x0)+f(xN)+2.*sum