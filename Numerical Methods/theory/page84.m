function untitled3(n)
%page84
ans = sm(n)
a=2:2:100;
indx=1;
for i=2:2:100
    ans(indx)=sm(i);
    indx=indx+1;
end
plot(a,ans);
end
function sm = sm(n)
sm=0;
for i=1:n
    sm=sm+1/i^2;
end
end