// Problem Link: https://leetcode.com/problems/range-sum-query-immutable/description/

class NumArray {
private:
    vector<int>prefix;
    int size;

public:
    NumArray(vector<int>& nums) {
        size=nums.size();
        if(size<1)
            return;
        
        prefix.push_back(nums[0]);

        for(int i=1;i<size;i++)
            prefix.push_back(nums[i]+prefix[i-1]);

    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return prefix[right];
    
        return prefix[right]-prefix[left-1];
    }
};
