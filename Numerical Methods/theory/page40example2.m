function [output] = untitled3(x, y)
%page40example2
if (x >= 0 & y >= 0)
    output = x + y
elseif (x >= 0 & y < 0)
    output = x*y
elseif (x < 0 & y >= 0)
    output = x^2 +2*y^2
else
    output = x^2 +x*y
end