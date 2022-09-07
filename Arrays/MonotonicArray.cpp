/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.
*/
class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {   
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>=nums[i+1]) cnt1++;
            if(nums[i]<=nums[i+1]) cnt2++;
        }
        if(cnt1==nums.size()-1 or cnt2==nums.size()-1) return 1;
        return 0;
        
    }
};

/*
TC : O(N)
SC : O(1)
*/
