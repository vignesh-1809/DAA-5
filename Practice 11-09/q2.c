#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maximizeCoins(int pots[], int n) {
    int dp[n][n];

    for (int i = 0; i < n; i++) {
        dp[i][i] = pots[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            int pickLeft = pots[i] + ((i + 2 <= j) ? dp[i + 2][j] : 0);
            int pickRight = pots[j] + ((i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0);
            dp[i][j] = max(pickLeft, pickRight);
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of pots: ");
    scanf("%d", &n);

    int pots[n];
    printf("Enter the values of the pots:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pots[i]);
    }

    int totalCoins = maximizeCoins(pots, n);
    printf("Total coins collected by Player A: %d\n", totalCoins);

    int totalCoinsByB = 0;
    for (int i = 0; i < n; i++) {
        totalCoinsByB += pots[i];
    }
    totalCoinsByB -= totalCoins;
    printf("Total coins collected by Player B: %d\n", totalCoinsByB);

    return 0;
}
