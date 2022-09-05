//Approch : 1
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]*nums[i];
        }
       sort(nums.begin(),nums.end());
       return nums;
        
    }
};
/*
TC :O(NlogN)
SC :O(1)
*/

//Approch :2
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> v;
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        { 
          int smallvalue = nums[l];
          int largervalue = nums[r];
          
          if(abs(smallvalue) >abs(largervalue))
          {
              v.push_back(smallvalue*smallvalue);
              l++;
          }
            else
            {
              v.push_back(largervalue*largervalue);
              r--; 
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

  
/*
TC:O(N)
SC:O(N)
*/
