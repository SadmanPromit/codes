x=0:.1:1;
y=@(x) sin(2.*pi.*x);
figure(1);
plot(x,y(x),'r.');
figure(2);
plot(6,0,'o',0,6,'o',1,1,'o');
hold on;
p = nsidedpoly(3, 'Center', [1 ,1], 'SideLength', 1);
pgon = polyshape([6 0 1],[0 6 1]);
plot(pgon);
hold off;
A=[6 0]; B=[0 6]; C=[1 1];
AB=distance(A,B)
BC=distance(B,C)
CA=distance(C,A)
s=(A+B+C)/2;
Area=sqrt(s.*(s-A).*(s-B).*(s-C))