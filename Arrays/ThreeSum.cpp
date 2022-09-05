/*
idea : Two pointer approch
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int l,r,sum; 
        vector<vector <int>> v;
        for(int i=0;i<nums.size();i++)
        {    
          if(i>0 and nums[i]==nums[i-1]) continue; // check for duplicates for first element in triplets.
             l=i+1;
             r=nums.size()-1;
            while(l<r)
            {
                sum=nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                     v.push_back({nums[i],nums[l],nums[r]});
                       int a=nums[l];
                       while(l<r && nums[l]==a) l++; // avoiding duplicate triplets with same left pointer values
                       int b=nums[r];
                       while(l<r && nums[r]==b) r--;// avoiding duplicate triplets with same right pointer values
                       
                }
                else if(sum<0)l++;
                else r--;
            }
           
        }
        return v;
    }
};
/*
Time Complexity : o(N^2)
space complexity : o(N)
*/
