#include <stdio.h>
double getAverage(int arr[], int size) {
    int i;
    double avg, sum = 0;
    for(i = 0; i < size; i++)
        sum += arr[i];
    avg = sum / size;
    return avg;
}
void main() {
  int balance[5] = {1000, 2, 3, 17, 50};
  double avg;
  avg = getAverage(balance, 5);
  printf("Average is: %f \n", avg);
}
