#include <stdio.h>

int sum_of_digits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int sum_of_distinct_digits(int n) {
    int a[10] = {0};
    int sum = 0;

    while (n != 0) {
        int digit = n % 10;
        if (a[digit] == 0) {
            sum += digit;
            a[digit] = 1;
        }
        n /= 10;
    }

    return sum;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int p= sum_of_digits(n);
    int q= sum_of_distinct_digits(n);

    printf("Sum of digits of %d is %d\n", n, p);
    printf("Sum of distinct digits of %d is %d\n", n,q);

    return 0;
}
