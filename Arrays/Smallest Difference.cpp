/*Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative) difference. 
Return the pair with smallest difference*/
/*idea : Bute force takes use of two for loops which contributes a time complexity of O(N^2)
better approch involves make of use of sorted arrays.
*/

class Solution
{
  public:
  vector<int> smallDifference(vector<int>&a, vector<int> &b)
  {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int idxone=0;
    int idxtwo=0;
    int smallest=INT_MAX;
    int current =INT_MAX;
    while(idxone<a.size() and idxtwo<b.size())
    {
      firstnum =a[idxone];
      secondnum =b[idxtwo];
      if(
    }
    
  }
};
