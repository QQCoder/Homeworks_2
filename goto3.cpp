#include <iostream>

using namespace std;

const int ARR_L = 10;

struct Array {
    int arr[ARR_L];
};

int sum(Array *array) {
    int result = 0;
    int i = 0;
    f1:
    {
        if (i < ARR_L) {
            result += array->arr[i];
            i++;
            goto f1;
        }
    }
    return result;
}

int main() {
    Array *array = new Array;
    for (int i = 0; i < ARR_L; i++) {
        array->arr[i] = rand() % 5 + 1;
    }
    for (int i = 0; i < ARR_L; i++) {
        cout << array->arr[i] << " ";
    }
    cout << endl;
    int s = sum(array);
    cout << s;
}