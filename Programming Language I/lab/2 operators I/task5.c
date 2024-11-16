#include<stdio.h>
void main() {
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	int last = n % 10;
	int others = n / 10;
	printf("Last digit: %d", last);
	printf("\nOther digits: %d", others);
}
