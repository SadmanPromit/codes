function untitled3(n)
%page97
j=0;
for i=0:n
    if(mod(i,2)~=0)
        if(mod(i,3)~=0)
            j=j+1;
            mat(1,j)=i;
        end
    end
end
j=0;
for i=0:n
    if(mod(i,2)==0)
        if(mod(i,3)~=0)
            j=j+1;
            mat(2,j)=i;
        end
    end
end
j=0;
for i=0:n
    if(mod(i,3)==0)
        j=j+1;
        mat(3,j)=i;
    end
end
mat
end