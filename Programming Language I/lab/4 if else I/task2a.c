void main() {
    int x,y,z;
    //Reads any three integer values from user
    printf("Enter three distinct numbers: ");
    scanf("%d %d %d", &x, &y, &z);
    //Check if x is the minimum
    if(x < y && x < z)
        printf("\n%d is minimum.\n", x);
    //if x is not min then y or z is min; Check which.
    else if(y < z)
        printf("\n%d is minimum.\n", y);
    else
        printf("\n%d is minimum.\n", z);
}

