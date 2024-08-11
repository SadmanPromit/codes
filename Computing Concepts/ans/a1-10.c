#include <stdio.h>
int main() {
    float n;
    printf("Enter Richter Scale Number(n): ");
    scanf("%f", &n);
    if(n < 5.0)
        printf("Characterization: Little or no damage\n");
    else if(n >= 5.0 && n < 5.5)
        printf("Characterization: Some damage\n");
    else if(n >= 5.5 && n < 6.5)
        printf("Characterization: Serious damage walls may crack\n");
    else if(n >= 6.5 && n < 7.5)
        printf("Characterization: Disaster: Houses and buildings may collapse\n");
    else
        printf("Characterization: Catastrophe, most buildings destroyed\n");
    return 0;
}
