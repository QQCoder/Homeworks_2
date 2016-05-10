#include <iostream>

using namespace std;

const int ARR_L = 10;

struct Array {
    int arr[ARR_L];
};

int getMax(Array *array) {
    int result = array->arr[0];
    int i = 1;
    f1:
    {
        if (i < ARR_L) {
            if (result < array->arr[i]) {
                result = array->arr[i];
            }
            i++;
            goto f1;
        }
    }
    return result;
}

int main() {
    Array *array = new Array;
    for (int i = 0; i < ARR_L; i++) {
        array->arr[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < ARR_L; i++) {
        cout << array->arr[i] << " ";
    }
    cout << endl;
    int max = getMax(array);
    cout << max << endl;
}