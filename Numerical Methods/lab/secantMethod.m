clc;
clear all;
x0=input('Enter x0:');
x1=input('Enter x1:');
iteration=0;
tol=1e-10;
f=@(x)(x-cos(x));
while(abs(x1-x0)>tol)
    x2=x1-((x1-x0)*f(x1)/(f(x1)-f(x0)));
    x0=x1;
    x1=x2;
    iteration=iteration+1;
end
root=x2
iteration