#include <stdio.h>
struct Distance {
    int feet;
    float inch;
} d1, d2, sum;
int main(){
    printf("1st distance\nEnter feet: ");
    scanf("%d", &d1.feet);  // input of feet for structure variable d1
    printf("Enter inch: ");
    scanf("%f", &d1.inch);  // input of inch for structure variable d1
    printf("2nd distance\nEnter feet: ");
    scanf("%d", &d2.feet);  // input of feet for structure variable d2
    printf("Enter inch: ");
    scanf("%f", &d2.inch);  // input of inch for structure variable d2
    sum.feet = d1.feet + d2.feet;
    sum.inch = d1.inch + d2.inch;
    if (sum.inch >= 12) {    //If inch is greater than 12, changing it to feet.
        ++sum.feet;
        sum.inch -= 12;
    }
    printf("Sum of distances = %d\' %.1f\"\n", sum.feet, sum.inch);
}
