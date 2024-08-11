function divs=divisors(n)
%divisors(n) gives a list of the integers that
% divides n and tests if it is a perfect number
sum = 0;
for i=1:n-1
    if mod(n,i)==0
        disp(i);
        sum = sum + i;
    end
end
if sum == n
fprintf('%d is a perfect number\n',n)
else
fprintf('%d is not a perfect number\n',n)
end
end % end of the code