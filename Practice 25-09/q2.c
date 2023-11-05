#include <stdio.h>
int countChangeBF(int coins[], int n, int amount) {
    if (amount == 0) return 1;
    if (amount < 0 || (n <= 0 && amount >= 1)) return 0;
    return countChangeBF(coins, n - 1, amount) + countChangeBF(coins, n, amount - coins[n - 1]);
}

int main() {
    int amt;
    printf("enter the amount:");
    scanf("%d",&amt);
    int coins1[] = {1, 3, 5};
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    int amount1 = amt;

    int coins2[] = {1, 3, 4};
    int n2 = sizeof(coins2) / sizeof(coins2[0]);
    int amount2 = amt;
    int coins3[3];
    printf("Enter coins3 values:");
    for(int i=0;i<3;i++)
    {
        scanf("%d",&coins3[i]);
    }
    int n3 = sizeof(coins3) / sizeof(coins3[0]);
    int amount3 = amt;
    int n4;
    printf("Enter the number of coins:");
    scanf("%d",&n4);
    int coins4[n4];
    printf("Enter the value of coins:");
    for(int i=0;i<n4;i++)
    {
        scanf("%d",&coins4[i]);
    }
    int amount4 = amt;

    printf("(i) Number of ways to make change: %d\n", countChangeBF(coins1, n1, amount1));
    printf("(ii) Number of ways to make change: %d\n", countChangeBF(coins2, n2, amount2));
    printf("(iii) Number of ways to make change: %d\n", countChangeBF(coins3, n3, amount3));
    printf("(iv) Number of ways to make change: %d\n", countChangeBF(coins4, n4, amount4));

    return 0;
}
