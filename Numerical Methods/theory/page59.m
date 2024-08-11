function p1
x=-2:.2:2; y=-2:.2:2;
z=f(x,y); figure(1); subplot(121); surf(y,x,z)
xlabel('y','fontsize',14); ylabel('x','fontsize',14)
subplot(122); mesh(y,x,z)
xlabel('y','fontsize',14); ylabel('x','fontsize',14)
figure(2)
[X,Y] = meshgrid(-2:.2:2, -2:.2:2);
Z = X.^2 + Y.^2; mesh(X,Y,Z)
xlabel('y','fontsize',14);
ylabel('x','fontsize',14)
end
function z=f(x,y);
for i=1:length(x)
for j=1:length(y)
z(i,j)=x(i).^2+y(j).^2;
end
end
end