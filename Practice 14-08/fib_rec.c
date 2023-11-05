#include <stdio.h>

int fibonacciRecursive(int n, int fib[]) {
    if (n <= 1) {
        fib[n] = n;
        return n;
    }

    if (fib[n] != -1) {
        return fib[n];
    }

    fib[n] = fibonacciRecursive(n - 1, fib) + fibonacciRecursive(n - 2, fib);
    return fib[n];
}

void printFibSeries(int fib[], int n) {
    printf("Fibonacci Series up to %d:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int fib[n + 1];
    for (int i = 0; i <= n; i++) {
        fib[i] = -1; 
    }

    int result = fibonacciRecursive(n, fib);

    printFibSeries(fib, n);
    

    return 0;
}
