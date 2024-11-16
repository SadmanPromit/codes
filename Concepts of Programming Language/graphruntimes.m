clear all; clc;
size = [16  32  64  128  256];
CpT = [0.000000 0.000000 0.002000 0.006000 0.050000];
CaT = [0.000000 0.000000 0.001000 0.007000 0.047000];
JT = [1.25E-4 8.029E-4 0.0019752 0.0062131 0.0340999];
PT = [0.0 0.0 0.0010006427764892578 0.0019989013671875 0.016061067581176758];
cp = interp1(size, CpT); ca = interp1(size, CaT); java = interp1(size, JT); python = interp1(size, PT);
plot(size, CpT, 'o', size, CaT, 'o', size, JT, 'o', size, PT, 'o'); legend('Cp', 'Ca', 'Java', 'Python');
title("Matrix Size vs Run time")
xlabel("Matrix Size")
ylabel("Run time(Seconds)")
grid on
axis square