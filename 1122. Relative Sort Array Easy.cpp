PROBLEM:https://leetcode.com/problems/relative-sort-array/description/

VIDEO (PRINCE BHAIYA) :https://youtu.be/bNuMPAuQN4g
/*
TC:
SC:
*/

#include<vector>
#include<map>
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int,int>mp;
        //iterate in arr1 to get the frequency of each element
        for(auto x:arr1){
         mp[x]++;
        }

        //traverse in arr2

        for(auto y:arr2){
            if(mp.find(y)!=mp.end()){
                auto temp=mp.find(y);
                int count=temp->second;
                int ele=temp->first;
                vector<int>v(count,ele);
                ans.insert(ans.end(),v.begin(),v.end());
                mp.erase(y);

            }
        }

        //traverse in map
        for(auto it:mp){
            int ele=it.first;
            int cnt=it.second;
            vector<int>v(cnt,ele);
            ans.insert(ans.end(),v.begin(),v.end());
        }
     return ans;
    }
};
