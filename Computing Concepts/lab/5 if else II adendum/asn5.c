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
    switch(direction) {
        case 'N':
            y += unit;
            break;
        case 'S':
            y -= unit;
            break;
        case 'E':
            x += unit;
            break;
        case 'W':
            x -= unit;
            break;
        default:
            printf("Wrong input.\n");
            exit(0);
    }
    printf("New coordinate: (%d,%d)\n", x, y);
    return 0;
}
