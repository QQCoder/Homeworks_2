#include <iostream>
#include <stdlib.h>

using namespace std;

const int ARR_L = 10;

struct Array {
    int arr[ARR_L];
};

void changeArray(Array *&array) {
    Array *result = new Array;
    int j = 0;
    int i;
    i = 0;
    f1:
    {
        if (i < ARR_L) {
            if (array->arr[i] < 0) {
                result->arr[j] = array->arr[i];
                j++;
            }
            i++;
            goto f1;
        }
    }
    i = 0;
    f2:
    {
        if (i < ARR_L) {
            if (array->arr[i] >= 0) {
                result->arr[j] = array->arr[i];
                j++;
            }
            i++;
            goto f2;
        }
    }
    array = result;
}

int main() {
    Array *array = new Array;
    for (int i = 0; i < ARR_L; i++) {
        array->arr[i] = rand() % 1000 - 500;
    }
    for (int i = 0; i < ARR_L; i++) {
        cout << array->arr[i] << " ";
    }
    cout << endl;
    changeArray(array);
    for (int i = 0; i < ARR_L; i++) {
        cout << array->arr[i] << " ";
    }
}