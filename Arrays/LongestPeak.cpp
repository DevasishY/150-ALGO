/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
*/
/*
Idea : first find peak and simentanously travel backward and front from current peak and
identify length which satisfies above condition corresponding to each peak and update to get longest peak length 
*/
class Solution {
public:
    
    int longestMountain(vector<int>& arr) 
    {
        int pl=0;
        int n=arr.size();
        for(int i=1;i<n-1;i++)
        {   
            int cnt=1;
            if(arr[i]>arr[i+1] and arr[i]>arr[i-1])
            {
               int j=i;
               while(j>=1 and arr[j]>arr[j-1])
               {
                   cnt++;
                   j--;
               }
                while(i<=n-2 and arr[i]>arr[i+1])
                {
                    cnt++;
                   i++;
                }
                pl=max(cnt,pl);
            }
        }
        return pl;
        
    }
};
/*
TC : O(N)
SC : O(1)
*/
