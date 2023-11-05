#include <stdio.h>

void fib_iter(int n) {
    int f[n + 1];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    printf("The %dth Fibonacci number is %d\n", n, f[n]);
    printf("The Fibonacci series up to the %dth number is: ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", f[i]);
    }
}

int main() {
    int n ; 
  scanf("%d",&n);
    fib_iter(n);
    return 0;
}
