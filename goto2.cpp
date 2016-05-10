#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int ARR_L = 10;

struct Array {
    int arr[ARR_L];
};

int indexOfInArray(int t, Array *array) {
    int i = 0;
    f1:
    {
        if (i < ARR_L) {
            if (array->arr[i] == t) {
                return i;
            }
            i++;
            goto f1;
        }
    }
    return -1;
}

int main() {
    Array *array = new Array;
    for (int i = 0; i < ARR_L; i++) {
        array->arr[i] = rand() % 10 + 1;
    }
    for (int i = 0; i < ARR_L; i++) {
        cout << array->arr[i] << " ";
    }
    cout << endl;
    int index = indexOfInArray(3, array);
    cout << index << endl;
}