PROBLEM:https://www.geeksforgeeks.org/smallest-subarray-with-sum-k-from-an-array/
VIDEO:

/*
BRUTE FORCE
TC:O(N^2)
SC:O(1)
INTUITION
1.run two for loops and generate every possible subarray and if its sum==k then update minimum size of subarray
2.return min_size
*/

#include <bits/stdc++.h>
using namespace std;
int minSize(vector<int>&nums,int k){
    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(sum==k){
                mini=min(mini,j-i+1);
            }
        }
    }
    return mini;
}
int main() {
    vector<int>v={2, 4, 6, 10, 2, 1};
    vector<int>v1={-8, -8, -3, 8};
	cout<<minSize(v1,5);
	return 0;
}

/*
using hashing
tc:O(N)
sc:O(N)
INTUITION
1. use a map to store the prefixSum ending at the ith index
2. store current prefix sum till ith index
3. store minimum size subarray whose sum is K.
4. Check if the current prefix sum is equals to K
5. required prefix sum
6. check if there exists any required Prefix Sum
7. store the current prefix sum ending at i
8.return result
*/

#include <bits/stdc++.h>
using namespace std;

int smallestSubarraySumK(vector<int>&arr,int k){
    //use a map to store the prefixSum ending at the ith index
    unordered_map<long long ,int>mp;
    int n=arr.size();
    //store current prefix sum till ith index
    long long currPrefixSum=0;
    
    //store minimum size subarray whose sum is K.
    long long result=INT_MAX;
    for(int i=0;i<n;i++){
        currPrefixSum+=arr[i];
	    // Check if the current prefix sum is equals to K
        if(currPrefixSum==k){
            long long currlen=i+1;
            result=min(result,currlen);
            
        }
        //required prefix sum
        long long requiredPrefixSum=currPrefixSum-k;
        //check if there exists any required Prefix Sum
        if(mp.count(requiredPrefixSum)){
            long long foundIdx=mp[requiredPrefixSum];
            long long currIdx=i;
            result=min(result,currIdx-foundIdx);
        }
        // store the current prefix sum ending at i
        mp[currPrefixSum]=i;
    }
    if(result>=INT_MAX)return -1;
    return result;
    
}

int main() {
    vector<int>v={2, 4, 6, 10, 2, 1};
    vector<int>v1={-8, -8, -3, 8};
	cout<<smallestSubarraySumK(v,12)<<endl;;
	cout<<smallestSubarraySumK(v1,5);
	return 0;
}
