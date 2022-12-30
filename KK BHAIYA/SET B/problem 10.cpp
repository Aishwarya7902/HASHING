PROBLEM:https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
VIDEO:https://www.youtube.com/watch?v=kXkbW9pdgYc

/*
BRUTE FORCE
1.run 3 for loops
if a[i]+a[j]+a[k]==X return 1
*/

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++)
                if(A[i]+A[j]+A[k]==X)return true;
            }
        }
        return false;
    }

};



/*
tc:O(n^2)
sc:o(1)
something like 2 sum 
but isme hum ek no pahle hi nikal le rahe
*/
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        for(int i=0;i<n;i++){
            int y=X-A[i];
            int low=i+1,high=n-1;
            while(low<high){
                if(A[low]+A[high]==y)
                 return 1;
                else if(A[low]+A[high]>y)
                 high--;
                else
                 low++;
                 
            }
        }
        return 0;
    }
};

