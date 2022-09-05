/*
idea : traverse array by comparing subsequence given using two pointers and if both elemets match increament both pointers 
*/
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {   
        int l1=0;
        int l2=0;
        while(l2!=s.size() and l1!=t.size())
        {
            if(t[l1]==s[l2]) l2++,l1++;
            else
            {
                l1++;
            }
        }
      return (l2==s.size());
    }
};
/* 
TC : O(N)
sc : O(1)
*/
