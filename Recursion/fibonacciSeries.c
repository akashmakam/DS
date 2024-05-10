// Fibonacci series using recursion

#include <stdio.h>

void fibonacciSeries(int n, int a, int b) {
    if (n > 0) {
        printf("%d ", a);
        fibonacciSeries(n - 1, b, a + b);
    }
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    fibonacciSeries(n, 0, 1);

    return 0;
}