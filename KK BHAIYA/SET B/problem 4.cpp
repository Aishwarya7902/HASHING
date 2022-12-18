PROBLEM:https://leetcode.com/problems/continuous-subarray-sum/
VIDEO: https://www.youtube.com/watch?v=2K92SzwNaPg

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

/*
USING HASHING
TC:O(N)
SC:O(N)
FOR PSEUDO CODE....BETTER SEE THE SOLUTION VIDEO
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum%k)==mp.end()){
                mp[sum%k]=i+1;
            }
            else if(mp[sum%k]<i)
             return true;
        }
        return false;
    }
};
