// Problem Link: https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int add(int num1, int num2) {
    return (num1 % MOD + num2 % MOD) % MOD;
}

int mul(int num1, int num2) {
    return (1LL * num1 % MOD * num2 % MOD) % MOD; 
}

int numberOfWays(int n, int k) {
    if (n == 0) return 0;
    if (n == 1) return k; 

    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++) {
        int ans = add(mul(prev2, k - 1), mul(prev1, k - 1));
        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}
