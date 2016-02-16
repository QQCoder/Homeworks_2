#include <stdio.h>

struct R {
    int a, b;
};

void print(struct R arr[100], int t) {
    int i;
    printf("%d/%d", arr[0].a, arr[0].b);
    for (i = 1; i < t; i++) {
        printf(", %d/%d", arr[i].a, arr[i].b);
    }
}

void F(int n) {
    struct R arr[100];
    arr[0].a = 0;
    arr[0].b = 1;
    arr[1].a = 1;
    arr[1].b = 1;
    int j;
    int t = 2;
    for (j = 0; j <= n; j++) {
        int i = 0;
        while (i < t - 1) {
            if (arr[i].b + arr[i + 1].b == j) {
                int p;
                for (p = t + 1; p > i + 1; p--) {
                    arr[p] = arr[p - 1];
                }
                arr[i + 1].a = arr[i].a + arr[i + 2].a;
                arr[i + 1].b = arr[i].b + arr[i + 2].b;
                i++;
                t++;
            }
            i++;
        }
    }
    print(arr, t);
    return;
}

int main() {
    int n;
    printf("Enter some number: ");
    scanf("%d", &n);
    printf("\n");
    F(n);
    return 0;
}
