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
