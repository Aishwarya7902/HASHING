PROBLEM:https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/
VIDEO:

/*
BRUTE FORCE
TC:O(N^2)
SC:O(1)
INTUITION
1.run two for loops
2.for every i,j check if absolute diff==k , then cnt++
3.return cnt
*/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
      int cnt=0;
      for(int i=0;i<nums.size();i++){
          for(int j=i+1;j<nums.size();j++){
              if(abs(nums[i]-nums[j])==k)cnt++;
          }
      }
      return cnt;  
    }
};
