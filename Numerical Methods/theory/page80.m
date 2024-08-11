function soln_ode
% The function computes solution of the ode
% x'=x+t; x(0)=0.
tspan =[0 2]; x0=0;
[t,x]=ode23(@simpode,tspan,x0);
plot(t,x); xlabel('t'); ylabel('x')
end
function xdot=simpode(t,x)
% simpode computes xdot=x+t.
xdot=x+t;
end