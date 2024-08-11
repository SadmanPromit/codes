function [B,C] = untitled2(x,y)
%page62
B = [log(x) sin(y); x*y exp(-i*pi*y)]
z = transpose([1 2]);
C = B*z
end