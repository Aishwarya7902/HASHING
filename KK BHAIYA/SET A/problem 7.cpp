PROBLEM:https://www.geeksforgeeks.org/sum-of-elements-in-an-array-with-frequencies-greater-than-or-equal-to-that-element/?ref=rp

/*
USING HASHING
PSEUDO CODE:
1.take an unordered map
2.take a sum variable
3.traverse in arr and store frequency of each element in map
4.now traverse in map and if freq of element is greater than or equal to the element then add the element in sum
5.return sum
TC: O(N)
SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;
int sumFrequencyGreaterThanElement(vector<int>&arr){
    unordered_map<int,int>mp;
    int sum=0;
    //traverse in arr
    for(auto x:arr){
        mp[x]++;
    }
    
    //trvaerse in map
    for(auto it:mp){
        int ele=it.first;
        int freq=it.second;
        if(freq>=ele)
         sum+=ele;
    }
    return sum;
}
int main() {
	vector<int>arr={2, 1, 1, 2, 1, 6};//{1, 2, 3, 3, 2, 3, 2, 3, 3};
	cout<<sumFrequencyGreaterThanElement(arr);
  return 0;
}
