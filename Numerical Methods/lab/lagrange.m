clear all
clc
x = [150 152 154 156];
y = [12.247 12.329 12.410 12.490];
sum = 0;
a = 155;
for i = 1:length(x)
    u = 1;
    l = 1;
    for j = 1:length(x)
        if j ~= i
            u = u * (a - x(j));
            l = l * (x(i) - x(j));
        end
    end
    sum = sum + u / l * y(i);
end
sum