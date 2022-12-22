PROBLEM:https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
VIDEO:

/*
BRUTE FORCE
TC: O(n^2)
SC: O(1)
PSEDO CODE
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     int cnt=0;
     for(int i=0;i<nums.size();i++){
         int sum=0;
         for(int j=i;j<nums.size();j++){
             sum+=nums[j];
             if(sum%k==0)cnt++;
         }
     } 
     return cnt;  
    }
};
