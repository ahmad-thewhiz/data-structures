// recursion 
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        if(amt==0)
            return 0;
        
        if(amt<0)
            return INT_MAX;
        
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++) {
            int ans=coinChange(coins, amt-coins[i]);
            if(ans!=INT_MAX)
                mini=min(mini, 1+ans);
        }
        return (mini==INT_MAX)?-1:mini;
    }
};


// top-up
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt + 1, -1);
        return helper(coins, amt, dp);
    }
    
private:
    int helper(vector<int>& coins, int amt, vector<int>& dp) {
        if (amt == 0) 
            return 0;

        if (amt < 0) 
            return -1;

        if (dp[amt] != -1) 
            return dp[amt];

        int mini = INT_MAX;
        for (int coin : coins) {
            int res = helper(coins, amt - coin, dp);
            if (res != -1) 
                mini = min(mini, 1 + res);
        }

        dp[amt] = (mini == INT_MAX) ? -1 : mini;
        return dp[amt];
    }
};



// bottom-up

// algo
// step 1: declare a vector with the size of amt+1
// step 2: iterate over each value of amt
// step 3: then for each amount find the min num of combination of coins that can be used to achieve that amount

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX); 
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) { 
            for (int coin : coins)
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) 
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
