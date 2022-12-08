PROBLEM:https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1
VIDEO:https://www.youtube.com/watch?v=n5-uvGlhcCI&list=PLzjZaW71kMwQ-D3oxCEDHAvYu8VC1XOsS&index=9

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int,int>mp;
        //get freq of each element
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        //check
       for(int i=0;i<n;i++){
           if(mp[arr[i]]>1)
            return i+1;
        } 
        return -1;
    }
};
