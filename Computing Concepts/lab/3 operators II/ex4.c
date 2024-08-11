#include <stdio.h>
int main() {
    float x1, y1, x2, y2, midpointx, midpointy;
    printf("Enter (x1, y1), (x2, y2): ");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
    midpointx = (x1 + x2) / 2;
    midpointy = (y1 + y2) / 2;
    printf("Midpoint: (%.2f, %.2f)", midpointx, midpointy);
}

