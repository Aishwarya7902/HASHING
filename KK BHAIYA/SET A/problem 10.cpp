PROBLEM:https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

/*
brute force: gives TLE
tc:O(n^2)
sc:O(1)
intuition:

1.run two for loops , outer loop as i and inner as j, j starts from i+1

2.if arr[i]+arr[j]==k 
cnt++

3.return cnt
*/

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
      int cnt=0;
      for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
              if(arr[i]+arr[j]==k)cnt++;
          }
      }
      return cnt++;
    }
};

/*
OPTIMISATION : USING HASHING
TC:O(N)
SC:O(N)
INTUITION:
1.take a count variable
2.take an unordered map
3.if k-arr[i] is already present in map,then cnt+=mp[k-arr[i]]
4.put current element in map as it can be used in  future by someone else
5.return cnt

*/

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(k-arr[i])!=mp.end())
             cnt+=mp[k-arr[i]];
            
             mp[arr[i]]++;
        }
        return cnt;
    }
};
