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

/*
Using unordered map
Time: O(n + mk) where where n is size of nums, m is target size and k is the length of the resulting substring.
Space: O(n)
1.map to store frequency of every string occuring in nums
2. our target generate every possible pairs of sub string and check is that is present in map...if yes then nums[i]+nums[j]==target
3. string s1=target.substr(0,i); //this will bring substing from target staring from index 0 to i-1
   string s2=target.substr(i,n); //this will bring substing from target staring from index i to n-1
4.if(s1==s2){
  cnt+=mp[s1]*(mp[s2]-1);
 }//....?????why this formula let say for string 77 we have frequecy 3 in map and in nums this 77 is at 
 indices 0,1,2 hence the pair which we can form is ...{(0,1) ,(1,0),(0,2),(2,0),(1,2),(2,1)} 
 hence cnt is 6 which is mp[77]=3 hence 3*(3-1)=6 hence formula proved
5.else
     cnt+=mp[s1]*mp[s2];
6.return cnt;

*/

#include<bits/stdc++.h>
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int cnt=0; //this will store our ans
        int n=target.size();
        unordered_map<string,int>mp;//to store frequency of every string occuring in nums
        for(auto digit:nums){
         mp[digit]++;
        }
        //for our target generate every possible pairs of sub string and check is that is present in map...if yes then nums[i]+nums[j]==target
        for(int i=0;i<target.size();i++){
            string s1=target.substr(0,i); //this will bring substing from target staring from index 0 to i-1
            string s2=target.substr(i,n); //this will bring substing from target staring from index i to n-1
            if(s1==s2){
                cnt+=mp[s1]*(mp[s2]-1);
                }//....?????why this formula let say for string 77 we have frequecy 3 in map and in nums this 77 is at indices 0,1,2 hence the pair which we can form is ...{(0,1) ,(1,0),(0,2),(2,0),(1,2),(2,1)} hence cnt is 6 which is mp[77]=3 hence 3*(3-1)=6 hence formula proved
            else
             cnt+=mp[s1]*mp[s2];

            

        }
        return cnt;
    }
};
