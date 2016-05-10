#include <iostream>

using namespace std;

const int ARR_L = 10;

struct Array {
    int arr[ARR_L];
};

int multi(Array *array) {
    int result = 1;
    int i = 0;
    f1:
    {
        if (i < ARR_L) {
            result *= array->arr[i];
            i++;
            goto f1;
        }
    }
    return result;
}

int main() {
    Array *array = new Array;
    for (int i = 0; i < ARR_L; i++) {
        array->arr[i] = rand() % 2 + 1;
    }
    for (int i = 0; i < ARR_L; i++) {
        cout << array->arr[i] << " ";
    }
    cout << endl;
    int m = multi(array);
    cout << m << endl;
}