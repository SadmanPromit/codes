#include <stdio.h>
int main() {
    int angle_a, angle_b, angle_c;
    printf("Enter triangle angles a, b, c in degree: ");
    scanf("%d%d%d", &angle_a, &angle_b, &angle_c);
    if(angle_a + angle_b + angle_c == 180)
        printf("Valid triangle.");
    else
        printf("Invalid triangle.");
    return 0;
}
