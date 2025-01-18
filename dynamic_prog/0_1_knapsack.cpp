// Problem Link: https://www.naukri.com/code360/problems/0-1-knapsack_920542

#include <bits/stdc++.h> 

// int solve(vector<int> weight, vector<int> value, int n, int maxWeight) {
// 	if(n==0 || maxWeight==0)
// 		return 0;
	
// 	if(weight[n-1]>maxWeight) // if the weight of current obj is greater than max weight, simple move onto the next
// 		return solve(weight, value, n-1, maxWeight);

// 	return max(value[n-1]+solve(weight, value, n-1, maxWeight-weight[n-1]), solve(weight, value, n-1, maxWeight));
// }


// int memoization(vector<int>& weight, vector<int>& value, int idx, int maxWeight, vector<vector<int>>& dp) {
//     // Base case: If there's only one item
//     if (idx == 0) {
//         if (weight[0] <= maxWeight)
//             return value[0];
//         else
//             return 0;
//     }

//     // If the value is already computed
//     if (dp[idx][maxWeight] != -1)
//         return dp[idx][maxWeight];

//     // If the current item's weight exceeds the remaining capacity
//     if (weight[idx] > maxWeight)
//         return dp[idx][maxWeight] = memoization(weight, value, idx - 1, maxWeight, dp);

//     // Otherwise, consider including and excluding the current item
//     dp[idx][maxWeight] = max(
//         value[idx] + memoization(weight, value, idx - 1, maxWeight - weight[idx], dp),
//         memoization(weight, value, idx - 1, maxWeight, dp)
//     );

//     return dp[idx][maxWeight];
// }

int tabular(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// step 1: create dp array
	vector<vector<int>>dp(n+1, vector<int>(maxWeight+1, 0));
	
	// step 2: initialize the base case for first row
	// keep all the cols in row=0 from idx=0 to idx=weight[0] as 0 and rest all as value[0]
	for(int w=weight[0]; w<=maxWeight; w++) {
		if(weight[0]<=maxWeight)
			dp[0][w]=value[0];
		else
			dp[0][w]=0;
	}

	// step 3: calculate the remaining recursive calls
	for(int idx=1;idx<n;idx++) {
		for(int w=0;w<=maxWeight;w++) {
			int incl=0;

			if(weight[idx]<=w)
				incl=value[idx]+dp[idx-1][w-weight[idx]];

			int excl=0+dp[idx-1][w];

			dp[idx][w]=max(excl, incl);

		}
	}

	return dp[n-1][maxWeight];

}

int bestCase(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<int>curr(maxWeight+1, 0);

	for(int w=weight[0];w<=maxWeight;w++) {
		if(weight[0]<=maxWeight)
			curr[w]=value[0];
		else
			curr[w]=0;
	}

	for(int idx=1;idx<n;idx++) {
		for(int w=maxWeight;w>=0;w--) {
			int incl=0;

			if(weight[idx]<=w)
				incl=value[idx]+curr[w-weight[idx]];
			
			int excl=0+curr[w];

			curr[w]=max(incl, excl);
		}
	}

	return curr[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// return solve(weight, value, n, maxWeight);

	// vector<vector<int>>dp(n+1, vector<int>(maxWeight+1, -1));
	// return memoization(weight, value, n-1, maxWeight, dp);

	// return tabular(weight, value, n, maxWeight);

	return bestCase(weight, value, n, maxWeight);
}
