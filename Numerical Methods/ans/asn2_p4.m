clear all; clc;
format long g;
i = 1;
x1(i) = 0; x2(i) = 0; x3(i) = 0; x4(i) = 0;
Percentage_Diff_x1(i) = 9999;

while Percentage_Diff_x1(i) >= 0.00001
    x1(i + 1) = (6 + x2(i) - 2 * x3(i)) / 10;
    x2(i + 1) = (25 + x1(i) + x3(i) - 3 * x4(i)) / 11;
    x3(i + 1) = (-11 - 2 * x1(i) + x2(i) + x4(i)) / 10;
    x4(i + 1) = (15 - 5 * x2(i) + x3(i)) / 8;

    Percentage_Diff_x1(i + 1) = abs((x1(i + 1) - x1(i)) / x1(i + 1)) * 100;
    Percentage_Diff_x2(i + 1) = abs((x2(i + 1) - x2(i)) / x2(i + 1)) * 100;
    Percentage_Diff_x3(i + 1) = abs((x3(i + 1) - x3(i)) / x3(i + 1)) * 100;
    Percentage_Diff_x4(i + 1) = abs((x4(i + 1) - x4(i)) / x4(i + 1)) * 100;
    
    i = i + 1;
end

Jacobi_Number_of_iterations = i
disp('                        x1                  error(%)');
disp([round(x1,5)', round(Percentage_Diff_x1,5)'])
disp('                        x2                  error(%)');
disp([round(x2,5)', round(Percentage_Diff_x2,5)'])
disp('                        x3                  error(%)');
disp([round(x3,5)', round(Percentage_Diff_x3,5)'])
disp('                        x4                  error(%)');
disp([round(x4,5)', round(Percentage_Diff_x4,5)'])

Percentage_Diff_x1(i) = 9999;
while Percentage_Diff_x1(i) >= 0.00001
    x1(i + 1) = (6 + x2(i) - 2 * x3(i)) / 10;
    x2(i + 1) = (25 + x1(i + 1) + x3(i) - 3 * x4(i)) / 11;
    x3(i + 1) = (-11 - 2 * x1(i + 1) + x2(i + 1) + x4(i)) / 10;
    x4(i + 1) = (15 - 5 * x2(i + 1) + x3(i + 1)) / 8;

    Percentage_Diff_x1(i + 1) = abs((x1(i + 1) - x1(i)) / x1(i + 1)) * 100;
    Percentage_Diff_x2(i + 1) = abs((x2(i + 1) - x2(i)) / x2(i + 1)) * 100;
    Percentage_Diff_x3(i + 1) = abs((x3(i + 1) - x3(i)) / x3(i + 1)) * 100;
    Percentage_Diff_x4(i + 1) = abs((x4(i + 1) - x4(i)) / x4(i + 1)) * 100;
    
    i = i + 1;
end

Gauss_Number_of_iterations = i
disp('                        x1                  error(%)');
disp([round(x1,5)', round(Percentage_Diff_x1,5)'])
disp('                        x2                  error(%)');
disp([round(x2,5)', round(Percentage_Diff_x2,5)'])
disp('                        x3                  error(%)');
disp([round(x3,5)', round(Percentage_Diff_x3,5)'])
disp('                        x4                  error(%)');
disp([round(x4,5)', round(Percentage_Diff_x4,5)'])