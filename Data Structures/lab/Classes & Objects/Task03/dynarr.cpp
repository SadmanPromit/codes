#include "dynarr.h"
#include <iostream>
using namespace std;

dynArr::dynArr() {
    data = NULL;
    size = 0;
}

dynArr::dynArr(int row, int column) {
    int **data = new int*[row];
    for (int i = 0; i < row; i++)
        data[i] = new int[column];
}

dynArr::~dynArr() {
    delete [] data;
}

int dynArr::getValue(int row, int column) {
    return data[row][column];
}
void dynArr::setValue(int row, int column, int value) {
    data[row][column] = value;
}
