x = [1 2 3 4 5 6];
y = [3 1 4 1 5 9];
p = polyfit(x,y,5)
xnew=3.5;
ynew=interp1(x,y,xnew)

x1 = [21 12 13 44 15 61];
mean=mean(x1)
median=median(x1)
maximum=max(x1)
minimum=min(x1)
cumulativesum=cumsum(x1)