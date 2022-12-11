PROBLEM:
VIDEO (PRINCE BHAIYA):

/*
method 1 (done on my own)
TC:
SC:
*/


class Solution {
bool static comp(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second)
     return a.first>b.first;
    else
     return a.second<b.second;
}
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<pair<int,int>>p;
        for(auto it:mp){
            int freq=it.second;
            int ele=it.first;
            p.push_back(make_pair(ele,freq));
        }
        sort(p.begin(),p.end(),comp);
        for(auto it:p){
            int freq=it.second;
            int ele=it.first;
            vector<int>v(freq,ele);
            ans.insert(ans.end(),v.begin(),v.end());
        }
        return ans;

    }
};

/*
METHOD 2: 
LEARNING 🔥🔥 :learnt lambda function
TC:
SC:
*/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
       unordered_map<int,int>mp;
       for(auto x:nums){
           mp[x]++;
       }

       sort(nums.begin(),nums.end(),[&](int a,int b){
           return mp[a]!=mp[b] ? mp[a]<mp[b] : a>b;
       });
       return nums; 
    }
};
