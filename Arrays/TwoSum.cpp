class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
       map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
          int value=target-nums[i];
          if(m.find(value)!=m.end())
          {
              v.push_back(m[value]);
              v.push_back(i);
          }
          else
          {
              m[nums[i]]=i;
          }
        }
        return v;
    }
};
