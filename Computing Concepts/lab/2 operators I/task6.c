#include <stdio.h>
void main() {
    int days, years, weeks;
    // Read total number of days (since the year 0 A.D.)
    printf("Enter days: ");
    scanf("%d", &days);
    // Converts days to years, weeks and days
    years = days / 365; // Ignoring leap year
    weeks = (days % 365) / 7;
    days = days - ((years * 365) + (weeks * 7));
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d", days);
}
