#include <iostream>

using namespace std;

const int ARR_L = 10;

struct Array {
    int arr[ARR_L];
};

bool arrayIsOrdered(Array *array) {
    int i = 1;
    f1:
    {
        if (i < ARR_L) {
            if (array->arr[i - 1] >= array->arr[i]) {
                return false;
            }
            i++;
            goto f1;
        }
    }
    return true;
}

int main() {
    Array *array = new Array;
    for (int i = 0; i < ARR_L; i++) {
        cin >> array->arr[i];
    }
    for (int i = 0; i < ARR_L; i++) {
        cout << array->arr[i] << " ";
    }
    cout << endl;
    bool ord = arrayIsOrdered(array);
    cout << (ord ? "ordered" : "not ordered");
    cout << endl;
}