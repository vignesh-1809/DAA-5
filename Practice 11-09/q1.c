#include <stdio.h>
#include <string.h>
#include <limits.h>

int isPalindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; 
        }
        start++;
        end--;
    }
    return 1; 
}

int minPartitions(char str[], int n) {
    int dp[n];
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j <= i; j++) {
            if (isPalindrome(str, j, i)) {
                int prevPartition = (j > 0) ? dp[j - 1] : 0;
                dp[i] = (dp[i] > prevPartition + 1) ? prevPartition + 1 : dp[i];
            }
        }
    }

    return dp[n - 1];
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int n = strlen(input);
    int minPartitionsCount = minPartitions(input, n);
    printf("Minimum number of partitions are: %d\n", minPartitionsCount);

    return 0;
}
