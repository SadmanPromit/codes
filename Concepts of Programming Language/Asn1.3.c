#include <stdio.h>
#include <stdlib.h>
#define pi 3.1416
#define dimension 5

int i, j, serialno[dimension][dimension], count = 1;
double radius[dimension][dimension], area[dimension][dimension], perimeter[dimension][dimension];

void calculation(int serialno[dimension][dimension], double radius[dimension][dimension], double area[dimension][dimension], double perimeter[dimension][dimension]) {
    for(i = 0; i < dimension; i++)
        for(j = 0; j < dimension; j++) {
            serialno[i][j] = count++;
            area[i][j] = (pi * radius[i][j] * radius[i][j]);
            perimeter[i][j] = 2 * pi * radius[i][j];
        }
}

int main(){
    printf("Enter 25 radiuses: ");
    for(i = 0; i < dimension; i++)
        for(j = 0; j < dimension; j++)
            scanf("%lf", &radius[i][j]);
    calculation(serialno, radius, area, perimeter);
    char str[(sizeof(serialno) + sizeof(radius) + sizeof(area) + sizeof(perimeter))/sizeof(double)];
    int s = 0;
    FILE *fp;
    fp = fopen("outputs.txt", "a");
    if(fp == NULL) {
        printf("Error while creating file!");
        exit(1);
    }
    fprintf(fp, "Serial No.\tRadius\tArea\tPerimeter\n");
    printf("Radius\tArea\n");
    for(i = 0; i < dimension; i++)
        for(j = 0; j < dimension; j++) {
            fprintf(fp, "%d\t%lf\t%lf\t%lf\n", serialno[i][j], radius[i][j], area[i][j], perimeter[i][j]);
            printf("%lf\t%lf\n", radius[i][j], area[i][j]);
        }
    fclose(fp);
}
