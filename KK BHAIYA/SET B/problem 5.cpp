PROBLEM:https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
VIDEO:
VERY HELPFUL BLOG:https://leetcode.com/problems/subarray-sums-divisible-by-k/solutions/413234/detailed-whiteboard-beats-100-do-you-really-want-to-understand-it/?orderBy=most_votes

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
/*
using hashing
tc:o(n)
sc:o(n)
pseudo code/intuition:
1.first we will calculate the prefixSum for each index
2.for prefixSum corresponding to each i ,we will trace its remainder in some map
3.traverse in nums....while traversing calculate prefixSum,
now for this prefixSum ,calculate the ramainder,
if this remainder is -ve....we will have to handlle this special case
kx+r 
i.e divisor*quotient+remainder
for negative remainders
kx-r ,then what we do in this case is we add k  and subtract k to it
kx-r+k-k, then it becomes
k(x-1)+(k-r) //here (k-r) is remainder

4.now there are two possibilities
i.when remainder is already present in map
..if it is so then it means that subarray in between has a sum which gives remainder zero,hence divisible by k,hence the subarray is
what we want ,therefore needs to be counted.
count+=mp[rem]
the no.that i need to increment the counter with is the frequency of the same remainder at its previous step.

5.mp[0]=1 ...........why???????????

if remainder is zero then we dont need to check something else ,since it is already satisfying the condition.

6.at last mp[rem]++ coz this subarray might be used in future

7.finally return count.

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int count=0;
      int sum=0;
      unordered_map<int,int>mp;
      mp[0]=1;
      for(int i=0;i<nums.size();i++){
          sum+=nums[i];
          int rem=sum%k;
          if(rem<0)rem+=k;
          if(mp.find(rem)!=mp.end()){
              count+=mp[rem];
          }
          mp[rem]++;
      }
      return count;  
    }
};
