/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> v;
        int n =nums.size();
        vector<int> productarray(n,1);
        int leftrunningproduct=1;
        int rightrunningproduct=1;
        for(int i=0;i<n;i++)
        {
            productarray[i]=leftrunningproduct;
            leftrunningproduct*=nums[i];
            
        }
        for(int i=n-1;i>=0;i--)
        {
            productarray[i]*=rightrunningproduct;
            rightrunningproduct*=nums[i];   
        }
        return productarray;
    }
};

/*
TC : O(N)
SC : O(N)
*/
