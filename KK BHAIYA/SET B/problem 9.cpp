PROBLEM:https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/
VIDEO:
BLOG:
/*
brute force:
tc:O(n^2)
sc:o(1)
intuition:
1.run two for loops...if nums[i]+nums[j]==target , cnt++;
*/

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
          for(int j=0;j<nums.size();j++){
            if(nums[i]+nums[j]==target && i!=j){
                ans++;
            }
          }
        }
        return ans;
    }
};
