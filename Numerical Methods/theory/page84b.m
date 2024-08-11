function untitled3(n)
%page84b while and if
ans = sm(n)
a=2:2:100;
indx=1;
i=2;
while i<=max(a)
    ans(indx)=sm(i);
    i=i+2;
    indx=indx+1;
end
plot(a,ans);
end
function sm = sm(n)
sm=0;
i=1;
while i<=n
    sm=sm+1/i^2;
    i=i+1;
end
end