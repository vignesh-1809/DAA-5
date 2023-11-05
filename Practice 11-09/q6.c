#include <stdio.h>

int kill(int n) {
    if (n == 1) {
        return 1;
    } else {
        return (kill(n - 1) + 2 - 1) % n + 1;
    }
}

int main() {
    int n;
    printf("Enter the number of people standing in the circle: ");
    scanf("%d", &n);

    int survivor = kill(n);
    printf("The person at position %d survives.\n", survivor);

    return 0;
}
