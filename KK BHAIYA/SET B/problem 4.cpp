PROBLEM:https://leetcode.com/problems/continuous-subarray-sum/
VIDEO:

/*
BRUTE FORCE:
tc:O(n^2)
sc:O(1)
pseudo code:
1.generate all possible subarrays and if sum is a mutiple of k return true
2.if none of the subarray sum is a multiple of k return false
*/


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       for(int i=0;i=nums.size()-1;i++){
           int sum=nums[i];
           for(int j=i+1;j<nums.size();j++){
               sum+=nums[j];
               if(sum%k==0)return true;
           }
       } 
       return false;
    }
};
