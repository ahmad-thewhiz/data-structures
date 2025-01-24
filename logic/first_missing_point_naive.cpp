// Problem Link: https://leetcode.com/problems/first-missing-positive/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minNum=INT_MAX, maxNum=INT_MIN, n=nums.size();;
        for(int num:nums) {
            if(num<minNum)
                minNum=num;
            if(num>maxNum)
                maxNum=num;
        }

        cout<<minNum<<" "<<maxNum;

        int ele=-1;
        if(minNum<1 && maxNum<1)
            return 1;
        else if(minNum>1 && maxNum>1)
            return 1;
        else {
            vector<bool>seen(n+1, false);

            for(int num:nums) {
                if(num>0 && num<=n)
                    seen[num]=true;
            }

            for(int i=1;i<=n;i++)
                if(!seen[i])
                    return i;
        }
        return n+1;
    }
};
