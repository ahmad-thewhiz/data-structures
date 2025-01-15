// Problem Link: https://www.naukri.com/code360/problems/cut-into-segments_1214651

#include<bits/stdc++.h>

using namespace std;

int bruteForce(int n, int x, int y, int z) {
	if(n==0)
		return 0;
	if(n==1)
		return INT_MIN;

	int sol1=bruteForce(n-x, x, y, z) +1;
	int sol2=bruteForce(n-y, x, y, z) +1;
	int sol3=bruteForce(n-z, x, y, z) +1;

	int ans=max(sol1, max(sol2, sol3));

	return ans;
}


int memoization(int n, int x, int y, int z, vector<int>&dp) {
	if(n==0)
		return 0;
	if(n<0)
		return INT_MIN;

	// step 1
	if(dp[n]!=INT_MIN)
		return dp[n];
	
	int sol1=memoization(n-x, x, y, z, dp)+1;
	int sol2=memoization(n-y, x, y, z, dp)+1;
	int sol3=memoization(n-z, x, y, z, dp)+1;

	// step 2
	dp[n] = max(sol1, max(sol2, sol3));
	return dp[n];
}

int solveTab(int n, int x, int y, int z) {
	vector<int>dp(n+1, INT_MIN);
	dp[0]=0;

	for(int i=1;i<=n;i++) {
		if(i-x>=0)
			dp[i]=max(dp[i], dp[i-x]+1);

		if(i-y>=0)
			dp[i]=max(dp[i], dp[i-y]+1);

		if(i-z>=0)
			dp[i]=max(dp[i], dp[i-z]+1);			
	}

	return (dp[n]<0)?0:dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// int ans=bruteForce(n,x,y,z);
	

	// vector<int>dp(n+1, INT_MIN);
	// int ans=memoization(n, x, y, z, dp);

	int ans=solveTab(n,x,y,z);

	return (ans<0)?0:ans;
}
