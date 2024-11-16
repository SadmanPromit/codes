void main() {
    int x,y,z;
    //Reads any three integer values from user
    printf("Enter three distinct numbers: ");
    scanf("%d %d %d", &x, &y, &z);
    //Check if x is the maximum
    if(x > y && x > z)
        printf("\n%d is maximum.\n", x);
    //if x is not max then y or z is max; Check which.
    else if(y > z)
        printf("\n%d is maximum.\n", y);
    else
        printf("\n%d is maximum.\n", z);
}
