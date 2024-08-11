void main() {
    int n1, n2;
    printf("Enter any two numbers:\n");
    scanf("%d %d", &n1, &n2);
    // Check if n1 > n2 or not and prints the maximum
    if(n1 > n2)
        printf("\n%d is maximum.\n", n1);
    else
        printf("\n%d is maximum.\n", n2);
}
