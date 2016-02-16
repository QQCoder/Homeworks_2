#include <stdio.h>
#include <stdbool.h>


int TryParse(char x[], bool *success){
    int i, number = 0;
    *success = false;
    for (i = 0; x[i]; i++){
        if ( (x[i] >= '0') && (x[i] <= '9') ){
            number = number * 10 + x[i] - '0';
        } else {
            *success = false;
            return -1;
        }
    }
    *success = true;
    return number;
}

int main() {
    bool succes;
    int number;
    char num[20];
    scanf("%s", num);
    number = TryParse(num, &succes);
    if (succes) {
        printf("Your number is %d", number);
    } else {
        printf("Value isn't a number");
    }
    return 0;
}
