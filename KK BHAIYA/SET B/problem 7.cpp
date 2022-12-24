PROBLEM:https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

/*
brute force 
tc:O(n^2)
sc:O(1)
intuition
1.run two for loops
2.find pair which sum up to k, and then remove from array
3.cnt++
4.return cnt

*/


/*
USING HASHING
TC:O(N)
SC:O(N)
INTUITION:
1.take a cnt
2.take a map
3.traverse in array 
4.if (k-nums[i]) is already present in map  then cnt++ ,and remove one occurance of (k-nums[i]) 
5.else , add nums[i] to map
NOTE: IF (k-nums[i]) is already present in map then we dont have to add nums[i] to map coz as said in question we have to remove pairs if they sum up to k

*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      int cnt=0;
      for(int i=0;i<nums.size();i++){
          if(mp[k-nums[i]]>0){
              cnt++;
              mp[k-nums[i]]--;
          }
          else{
              mp[nums[i]]++;
          }
      }
      return cnt;  
    }
};
