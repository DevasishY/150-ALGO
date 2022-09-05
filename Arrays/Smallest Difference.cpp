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
    vector<int> v;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int idxone=0;
    int idxtwo=0;
    int x=0;
    int y=0;
    int smallest=INT_MAX;
    int current =INT_MAX;
    while(idxone<a.size() and idxtwo<b.size())
    {
      int firstnum  = a[idxone];
      int secondnum = b[idxtwo];
      if(firstnum==secondnum) return v.push_back({firstnum,secondnum});
      v.clear();
      else if(firstnum>secondnum)
      {
        current = firstnum-secondnum;
        idxtwo++;
      }
      else if(secondnum>firstnum)
      {
        current =secondnum-firstnum;
        idxone++;
      }
      if(smallest>current)
      {
        smallest=current;
        x=firstnum;
        y=secondnum;
      }
    }
    v.push_back({x,y});
    return v;
    
  }
};

/*
TC : O(m log m + n log n)
SC : O(1)
*/
