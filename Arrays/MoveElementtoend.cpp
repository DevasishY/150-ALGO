/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/
class Solution {
public:
    void moveZeroes(vector<int>& v) 
    {
        int j = 0, n = v.size();
        for(int i = 0; i < n; ++i)
        {
            if(v[i] != 0)
            {
                swap(v[j], v[i]);
                j++;
            }
        }
    }
};
/*
TC : O(N)
SC : O(1)
*/
