// Problem Link: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h> 
using namespace std;

// recursive
// int solve(vector<int>&nums, int n) {
//     if(n<0)
//         return 0;
//     if(n==0)
//         return nums[0];

//     int incl=nums[n]+solve(nums, n-2);
//     int excl=0+solve(nums, n-1);
    
//     return max(incl, excl);
// }

// memoization
// int solveMem(vector<int>&nums, int n, vector<int>&dp) {
//     if(n<0)
//         return 0;
//     if(n==0)
//         return nums[0];

//     if(dp[n]!=-1)
//         return dp[n];

//     int incl=nums[n]+solveMem(nums, n-2, dp);
//     int excl=0+solveMem(nums, n-1, dp);

//     dp[n] = max(incl, excl);

//     return dp[n];
// }

// tabulation 
int sovleTab(vector<int>&nums) {
    int n=nums.size();

    vector<int>dp(n,0);

    dp[0]=nums[0];

    if (n > 1) {
        dp[1] = max(nums[0], nums[1]);
    }

    for(int i=2;i<n;i++) {
        int incl=dp[i-2]+nums[i];
        int excl=dp[i-1]+0;

        dp[i]=max(incl, excl);
    }

    return dp[n-1];
}

int solveBest(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = nums[0];                    // Maximum sum up to the 1st element
    int prev1 = max(nums[0], nums[1]);      // Maximum sum up to the 2nd element

    for (int i = 2; i < n; i++) {
        int incl = prev2 + nums[i];         // Include the current element
        int excl = prev1;                   // Exclude the current element
        int curr = max(incl, excl);         // Max sum at index i

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}


int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();

    // int ans=solve(nums, n-1);

    // vector<int>dp(n,-1);
    // int ans=solveMem(nums, n-1, dp);

    int ans=sovleTab(nums);

    return ans;
}
