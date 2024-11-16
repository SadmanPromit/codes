#include <stdio.h>
#include <math.h>
int main() {
    float radius, side;
    printf("Enter radius, r of a circle: ");
    scanf("%f", &radius);
    printf("Enter side, a of a square: ");
    scanf("%f", &side);
    if(2 * radius >= sqrt(2) * side)
        printf("Square can be placed inside that circle.");
    else
        printf("Square cannot be placed inside that circle.");
    return 0;
}
