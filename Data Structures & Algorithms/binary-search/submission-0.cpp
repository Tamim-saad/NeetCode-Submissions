
#include<bits/stdc++.h>
using namespace std;

class Solution{public:
		int search(vector<int>&nums, int target)
    {
      sort(nums.begin(), nums.end());
      int low=0;
      int high=nums.size()-1;
      while (low<high)
      {
        int mid=(low+high)/2;
        if(nums[mid]<target)
        {
          low=mid+1;
        }
        else{
          high=mid;
        }
      }
       if(nums[low]==target) 

      return low;
      return -1;
    }
    }; 
