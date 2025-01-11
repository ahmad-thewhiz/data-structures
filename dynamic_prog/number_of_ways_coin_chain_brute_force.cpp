#include <iostream>
#include <vector>

using namespace std;

int countWaysToMakeChange(const vector<int>& coins, int n) {
    int m = coins.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // If the coin is not included
            dp[i][j] = dp[i - 1][j];
            // If the coin is included
            if (j >= coins[i - 1]) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[m][n];
}

int main() {
    vector<int> coins = {2,3,5,10}; 
    int n;
    cout << "Enter the amount: ";
    cin >> n;

    int ways = countWaysToMakeChange(coins, n);
    cout << "Total number of ways to make change for " << n << " is: " << ways << endl;

    return 0;
}
