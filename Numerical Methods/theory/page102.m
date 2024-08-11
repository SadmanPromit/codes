function solution_ode(N)
%page102

% t belongs to [0, 2]
x(1)=0;
t(1)=0; % Number of points considered
h=2/N;
sum=0;
for i=2:N+1
    t(i) = i*h;
    x(i)= sum + h*f(sum,t(i));
    sum=x(i);
end
plot(t,x); xlabel('t'); ylabel('x');
end

function out = f(x, t)
% This function computes the
% function value of f(x, t) = x+t
out =x+t;
end
