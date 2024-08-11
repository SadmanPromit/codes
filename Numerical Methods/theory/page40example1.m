function [root1, root2] = quadratic(a, b, c)
%page40example1
D = b^2 - 4*a*c;
if (D > 0)
    root1 = (-b + sqrt(D))/(2*a);
    root2 = (-b - sqrt(D))/(2*a);
elseif (D == 0)
    root1 = -b / (2*a);
    root2 = root1;
else
    root1 = -b / (2*a) + (i - sqrt(-D))/(2*a);
    root2 = -b / (2*a) - (i - sqrt(-D))/(2*a);
end
sprintf('root1 = %.6f root2 = %.6f',root1, root2)