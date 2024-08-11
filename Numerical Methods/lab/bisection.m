clc;
format long
xup=pi;
xlow=0;
xmid=(xup+xlow)/2;
f=@(x) (x-cos(x));
number_of_iterations=0;
while (xup-xlow)>10^-4;
    if f(xlow)*f(xmid)<0;
        xup=xmid;
    else
        xlow=xmid;
    end
    xmid=(xup+xlow)/2;    
    number_of_iterations = number_of_iterations+1;
end
root=xmid
number_of_iterations