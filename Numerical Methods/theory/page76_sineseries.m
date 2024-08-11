%sineseries
n = [1 5 10 30];
x=pi/8;
sinx=0;
for j=1:4
    for i=1:length(n(j))
     sinx=sinx+(-1)^(i-1)*x^(2*i-1)/factorial(2*i-1);
    end
    sinx
end
