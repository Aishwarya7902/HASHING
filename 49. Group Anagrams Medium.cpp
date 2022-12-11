PROBLEM: https://leetcode.com/problems/group-anagrams/description/
VIDEO (BEST EVER VIDEO__PRINCE BHAIYA) : https://youtu.be/zX9k1XvVUXI


/*
TC:
SC:
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>>ans;
       unordered_map<string,vector<string>>mp;
       for(auto x:strs){
           string temp=x;
           sort(x.begin(),x.end());
           mp[x].push_back(temp);
       }
       for(auto it:mp){
           ans.push_back(it.second);
       } 
       return ans;
    }
};
