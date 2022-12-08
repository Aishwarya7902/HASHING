PROBLEM:https://practice.geeksforgeeks.org/problems/key-pair5616/1
VIDEO:https://www.youtube.com/watch?v=7xx1YcXXEYU&list=PLzjZaW71kMwQ-D3oxCEDHAvYu8VC1XOsS&index=11

LEARNING AT : # 8:15 mins of above video (😎🔥 jake dekho....aalas mat karo)
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int,int>mp;
	    for(int i=0;i<n;i++){
	       mp[arr[i]]++;
	    }
	    
	   for(auto it:mp){
	       int key=it.first;
	       int val=it.second;
	       int pair=x-key;
	       if(key==pair){
	           if(val>1)
	            return true;
	       }
	       else{
	           if(mp.count(pair))
	            return true;
	       }
	   }
	    return false;
	}
};
