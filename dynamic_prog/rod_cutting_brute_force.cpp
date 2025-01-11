#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rodCutting(const vector<int>& prices, int n) {
    vector<vector<int>> dp(prices.size() + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= prices.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) {
                dp[i][j] = max(dp[i-1][j], prices[i-1] + dp[i][j-i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    // The maximum revenue obtainable for length n is stored in dp[prices.size()][n]
    return dp[prices.size()][n];
}

int main() {
    vector<int> prices = {2, 5, 7, 13};
    
    int n;
    cin >> n;

    int maxRevenue = rodCutting(prices, n);
    cout << "Maximum revenue obtainable: " << maxRevenue << endl;

    return 0;
}
