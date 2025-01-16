// Problem Link: https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#define MOD 1000000007

#include<bits/stdc++.h>

// long long int baseCountDerangements(int n) {
//     // base
//     if(n==1)
//         return 0;
//     if(n==2)
//         return 1;
    
//     int ans = (n-1)%MOD * (((countDerangements(n-1)%MOD)+countDerangements(n-2)%MOD)%MOD);

//     return ans;
// }

// long long int solveMemoization(int n, vector<long long int>&dp) {
//     if(n==1)
//         return 0;
//     if(n==2)
//         return 1;
    
//     if(dp[n]!=INT_MIN)
//         return dp[n];
    
//     dp[n] = (n-1)%MOD * (((solveMemoization(n-1, dp)%MOD)+solveMemoization(n-2, dp)%MOD)%MOD);

//     return dp[n];
// }

long long int solveTab(int n) {
    vector<long long int>dp(n+1, 0);

    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++) {
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;

        long long int sum = (first+second)%MOD;

        long long int ans = ((i-1)*sum)%MOD;

        dp[i]=ans;
    }

    return dp[n];

}

long long int countDerangements(int n) {
    vector<long long int>dp(n+1, INT_MIN);

    long long int ans;
    
    // ans=solveMemoization(n, dp);
    ans=solveTab(n);

    if(ans!=INT_MIN)
        return ans;
    else
        -1;
}
