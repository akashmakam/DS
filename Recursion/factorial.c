// Factorial of a number using recursion

#include <stdio.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

int main() {
    int n;
    printf("\nEnter a number to find its factorial: ");
    scanf("%d", &n);
    printf("%d! = %d", n, factorial(n));
    return 0;
}