clear all; clc;
format long g;
i = 1;
x1(i) = 0; x2(i) = 0; x3(i) = 0;
Percentage_Diff_x1(i) = 9999;

while Percentage_Diff_x1(i) >= 0.00001
    x1(i + 1) = (7.85 + 0.1 * x2(i) + 0.2 * x3(i)) / 3;
    x2(i + 1) = (-19.3 - 0.1 * x1(i) + 0.3 * x3(i)) / 7;
    x3(i + 1) = (71.4 - 0.3 * x1(i) + 0.2 * x2(i)) / 10;
    
    Percentage_Diff_x1(i + 1) = abs((x1(i + 1) - x1(i)) / x1(i + 1)) * 100;
    Percentage_Diff_x2(i + 1) = abs((x2(i + 1) - x2(i)) / x2(i + 1)) * 100;
    Percentage_Diff_x3(i + 1) = abs((x3(i + 1) - x3(i)) / x3(i + 1)) * 100;
    
    i = i + 1;
end
Number_of_iterations = i
disp('                        x1                     error(%)');
disp([x1', Percentage_Diff_x1'])
disp('                        x2                     error(%)');
disp([x2', Percentage_Diff_x2'])
disp('                        x3                     error(%)');
disp([x3', Percentage_Diff_x3'])