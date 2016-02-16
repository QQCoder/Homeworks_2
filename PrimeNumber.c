#include <stdio.h>
#include <stdbool.h>

bool isPrime(int x) {
	int i;
	int result = 1;
	for (i = 2; i*i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int x;
	printf("Enter some number: ");
	scanf("%d", &x);
	if (isPrime(x)) {
		printf("%d is prime number", x);
	} else {
		printf("%d isn't prime number", x);
	}
	return 0;
}
