// top-bottom (memoization)
class Solution {
private:
    int minCost(vector<int>&cost, int n, vector<int>&dp) {
        if(n==0 || n==1)
            return cost[n];
        
        if(dp[n]!=-1)
            return dp[n];
        
        dp[n]=cost[n]+min(minCost(cost, n-1, dp), minCost(cost, n-2, dp));

        return dp[n];

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        vector<int>dp(n+1,-1);

        int ans=min(minCost(cost, n-1, dp), minCost(cost, n-2, dp));
        return ans;
    }
};

// bottom-up (tabulation)
class Solution {
private:
    int minCost(vector<int>& cost, int n) {
        vector<int> dp(n + 1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {  
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        return minCost(cost, n);
    }
};
