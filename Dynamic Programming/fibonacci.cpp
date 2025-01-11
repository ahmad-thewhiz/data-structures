// bottom-up approach 

int fib(int n) {
        if(n==0)
            return 0;

        vector<int>nums(n+1, 0);
        nums[0]=0;
        nums[1]=1;
        
        for(int i=2;i<=n;i++)
            nums[i]=nums[i-1]+nums[i-2];

        return nums[n];
    }  

// top-down approach
int fibonacci(int n, vector<int>&dp) {
        if(n==0 || n==1)
            return n;
        
        if(dp[n]!=-1)
            return dp[n];
        
        dp[n]=fibonacci(n-1, dp)+fibonacci(n-2, dp);

        return dp[n];
    }

    int fib(int n) {
        vector<int>dp(n+1, -1);
        return fibonacci(n, dp);
    }
