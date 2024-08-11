#include <iostream>
using namespace std;

void insertionSort(int A[], int length){
    int key, i;
    for(int j = 1; j < length; j++){
        key = A[j];
        i = j - 1;
        while(i > -1 && A[i] > key){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

void print(int a[], int length){
    for(int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {10, 6, 3, 2, 1, 8};
    int l = sizeof(arr)/sizeof(*arr);
    print(arr, l);
    insertionSort(arr, l);
    print(arr, l);
}
