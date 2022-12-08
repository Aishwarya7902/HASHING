PROBLEM:https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1
VIDEO:https://youtu.be/zgLtdM8-6CE

Expected Time Complexity: O(n + m).
Expected Auxiliary Space: O(min(n,m)).
  
  
class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        int ans=0;
        unordered_set<int>s;
        //store elements of a in map
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        //traverse in b
        for(int i=0;i<m;i++){
           if(s.find(b[i])!=s.end())
            ++ans;
            s.erase(b[i]);
        }
        return ans;
    }
};

