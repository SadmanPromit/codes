W=[100 -12 30; 55 95 20; -70 50 20];
A=W(3,2)
B=W(1,1)
C=W(3,3)
D=W(2,2)
E=A+B
F=sqrt(log(abs(C-D)))+cot(B)
n=input("Enter a number: ");
if(mod(n,2)==0)
    inpt=false
else
    inpt=true
end
syms x
a=5*diff(x^2+2*x+1)
b=int(5*x*x^2+2*x^5+3)
N=input("Enter N for Fibonacci series: ");
f(1)=0;
f(2)=1;
for i=3:N
    f(i)=f(i-1)+f(i-2);
end
Nth=f(N)
x=linspace(-2*pi,2*pi,100);
y1=sin(x);
y2=cos(x);
plot(y1,y2,'-');
