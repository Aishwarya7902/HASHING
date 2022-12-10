PROBLEM:https://practice.geeksforgeeks.org/problems/max-distance-between-same-elements/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

VIDEO:

/*
Expected Time Complexity : O(N)
Expected Auxilliary Space : O(N)
*/

class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
    int maxDist=0; //to store answer
    //make an unordered map to store the indices of first occurance of each 
    //element
    unordered_map<int,int>mp;
    
    // traverse in array and update maxDistance
    //kis element se maximu distance aa raha hume usse matlab ni,
    //hume bas masDist chahiye
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])!=mp.end()){
            auto it=mp.find(arr[i]);
            int firstIndx=it->second;
            maxDist=max(maxDist,i-firstIndx);
        }
        else{
            mp[arr[i]]=i;
        }
    }
    return maxDist;
    }
};
