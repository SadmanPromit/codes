clc
clear
%x=input('Enter the values of independent variable x in an array: \n');
x= [1:1:6]; % Write the values of independent variable x.
%y=input('Enter the values of dependent variable y in an array: \n');
y = [1 8 27 65 123 208]; % Write the values of dependent variable y.
xf=input('Enter the value of x where we want to find the value of f(x): ');
n=length(x); % Number of terms of X or Y
d=zeros(n-1);
h=x(2)-x(1); %step length
%Formula: f(u)?y(n)+u*(del)y(n-1)+u*(u+1)/2!(del)^2y(n-2)+....
%+u*(u+1)+..+(u+n-2)/(n-1)!(del)^(n-1)y(1)
%where h=x(2)-x(1)=step length and u=(xf-x(n))/h. Hree del:= forward
%difference operator.
u=(xf-x(n))/h;
for k=2:n %Calculation of first forward differences
    d(k-1,1)=y(k)-y(k-1);
end
for r=2:n-1  %Calculation of second and rest forward differences
    for k=1:n-r
        d(k,r)= d(k+1,r-1)-d(k,r-1);
    end
end
disp('The forward difference table is:')
d
s=y(n); t=u; m=n-1;
for r=1:n-1  %Calculation of result
    s=s+t*d(m,r);
    t=(u+r)/(r+1)*t;
    m=m-1;
end
fprintf('The required value is f(%1.2f)= %3.4f',xf,s);