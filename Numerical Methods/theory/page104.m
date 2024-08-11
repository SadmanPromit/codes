p=100;
r=.06;
n=4;
k=1:3;
A=p.*(1+r./n).^k
f = figure('Position',[10 10 600 600]);
dat = A;
columnHeaders = {'First','Second','Third'};
rowHeaders = {'Money($)'};
t = uitable('Parent',f,'Data',dat,'ColumnName',columnHeaders,... 
            'RowName',rowHeaders,'Position',[10 10 590 590]);