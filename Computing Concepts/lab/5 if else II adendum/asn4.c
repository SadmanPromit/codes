#include <stdio.h>
int main() {
    int x, y, unit;
    char direction;
    printf("Enter current coordinate (x and y positions): ");
    scanf("%d%d", &x, &y);
    printf("Enter No. units towards direction: ");
    scanf("%d", &unit);
    printf("Enter Direction: ");
    scanf(" %c", &direction);
    if(direction == 'N')
            y += unit;
    else if(direction == 'S')
            y -= unit;
    else if(direction == 'E')
            x += unit;
    else if(direction == 'W')
            x -= unit;
    else {
        printf("Wrong input.\n");
        exit(0);
    }
    printf("New coordinate: (%d,%d)\n", x, y);
    return 0;
}
