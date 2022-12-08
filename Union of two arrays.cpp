PROBLEM:https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
VIDEO:

Expected Time Complexity : O((n+m)log(n+m))  // we are using a set
Expected Auxilliary Space : O(n+m)

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_set<int>s;
        //traverse in a
        
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        
        //traverse in b
        
        for(int i=0;i<m;i++){
            s.insert(b[i]);
        }
        
        return s.size();
        
        
    }
};
