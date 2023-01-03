PROBLEM:https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
VIDEO:https://www.youtube.com/watch?v=kfFwnYXWR3U&t=637s

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       int n=nums.size();
       long long sum=0,maxo=0;
       map<int,int>check;
       for(int i=0;i<k-1;i++){
           check[nums[i]]++;
           sum+=nums[i];
       }
       for(int i=k-1;i<n;i++){
           check[nums[i]]++;
           sum+=nums[i];
           //if size==k it means map has k distinct elements
           if(check.size()==k){
               maxo=max(maxo,sum);
           }
            if(check[nums[i-k+1]]==1){ //edge case to handle k== 1
               check.erase(nums[i-k+1]);
           }
           else{
               check[nums[i-k+1]]--;
           }
           sum-=nums[i-k+1];
       }
       return maxo; 
    }
};
