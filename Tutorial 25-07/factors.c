#include <stdio.h>
#include <stdbool.h>
int c=0;
bool is_prime(int num) {
    c++;
    printf("D");
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

void find_prime_factors(int n) {
    printf("Prime factors of %d: ", n);

    for (int i = 2; i <= n; i++) {
        printf("%d\t%d\n",i,n);
         c++;
        while (n % i == 0) {

            printf("%d ", i);
            n /= i;
        }
    }

    printf("\n");
}

void find_all_factors(int n) {
    printf("All factors of %d: ", n);

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int find_sum_of_factors(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    find_prime_factors(n);

    printf("Prime factorization of %d: ", n);
    int temp = n;
    for (int i = 2; i <= n; i++) {
        while (temp % i == 0) {
            printf("%d", i);
            temp /= i;
            if (temp > 1) {
                printf(" x ");
            }
        }
    }
    printf("\n");

    find_all_factors(n);

    int sum_of_factors = find_sum_of_factors(n);
    printf("Sum of all factors of %d: %d\n", n, sum_of_factors);
    printf("count is : %d ",c);
    return 0;
}

