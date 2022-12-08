PROBLEM: https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1
VIDEO:https://www.youtube.com/watch?v=GySYmmehLM0&list=PLzjZaW71kMwQ-D3oxCEDHAvYu8VC1XOsS&index=13

/*
*/

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        vector<string>ans;
        map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int mx=INT_MIN;
        string final;
        for(auto x:mp){
            int val=x.second;
            if(val>mx){
                mx=val;
                final=x.first;
            }
            
        }
        ans.push_back(final);
        ans.push_back(to_string(mx));
        return ans;
    }
};
