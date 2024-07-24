#include <stdio.h>
#include <string.h>

#define MAX_N 20

int preferences[MAX_N][MAX_N];
int dp[1 << MAX_N];
int n;

// Function to count ways to assign topics to students
int countWays(int mask) {
    if (dp[mask] != -1) {
        return dp[mask];
    }

    int student = __builtin_popcount(mask); // Number of set bits (students assigned so far)
    if (student == n) {
        return 1;
    }

    int ways = 0;
    for (int topic = 0; topic < n; ++topic) {
        if ((mask & (1 << topic)) == 0 && preferences[student][topic] == 1) {
            ways += countWays(mask | (1 << topic));
        }
    }

    dp[mask] = ways;
    return dp[mask];
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &preferences[i][j]);
            }
        }

        memset(dp, -1, sizeof(dp));
        int result = countWays(0);

        printf("%d\n", result);
    }

    return 0;
}