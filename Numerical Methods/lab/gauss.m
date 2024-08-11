clear all; clc;
format long;
i = 1;
x1(i) = 0; x2(i) = 0; x3(i) = 0; x4(i) = 0;
Percentage_Diff_x1(i) = 9999;

while Percentage_Diff_x1(i) >= 0.00001
    x1(i + 1) = (6 + 1 * x2(i) - 2 * x3(i)) / 10;
    x2(i + 1) = (25 + 1 * x1(i+1) + 1 * x3(i) - 3 * x4(i)) / 11;
    x3(i + 1) = (-11 - 2 * x1(i+1) + 1 * x2(i+1) + x4(i)) / 10;
    x4(i + 1) = (15 - 3 * x2(i+1) + x3(i+1)) / 8;
    
    Percentage_Diff_x1(i + 1) = abs((x1(i + 1) - x1(i)) / x1(i + 1)) * 100;
    Percentage_Diff_x2(i + 1) = abs((x2(i + 1) - x2(i)) / x2(i + 1)) * 100;
    Percentage_Diff_x3(i + 1) = abs((x3(i + 1) - x3(i)) / x3(i + 1)) * 100;
    Percentage_Diff_x4(i + 1) = abs((x4(i + 1) - x4(i)) / x4(i + 1)) * 100;
    
    i = i + 1;
end
Number_of_iterations = i
disp('                        x1                     error(%)');
disp([x1', Percentage_Diff_x1'])
disp('                        x2                     error(%)');
disp([x2', Percentage_Diff_x2'])
disp('                        x3                     error(%)');
disp([x3', Percentage_Diff_x3'])
disp('                        x4                     error(%)');
disp([x4', Percentage_Diff_x4'])