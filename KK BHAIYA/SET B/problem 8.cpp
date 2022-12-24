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

/*
USING HASHING
blog:https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/solutions/1471324/c-simple-and-short-solution-using-map/?orderBy=most_votes
TC:O(N)
SC:O(N)
INTUITION:
1.In each iteration, we look how many numbers which have a k difference from our current number we have seen so far i.e we lool for k distance behind current no 
and k distance beyond current no
.
Then we add the current number to the map....
*/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
      int ans=0;
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
          ans+=mp[nums[i]-k]+mp[nums[i]+k];
          mp[nums[i]]++;
    
      } 
      return ans; 
    }
};
