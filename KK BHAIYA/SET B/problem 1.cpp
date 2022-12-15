PROBLEM: https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1
VIDEO:

/*
BRUTE FORCE:
TC: O(n^2)
SC: o(1)
INTUITION
1.for every subarrya , store its sum in sum variable 
2.if sum==k ,cnt++
3.return cnt
*/

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int cnt=0;
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=i;j<N;j++){
                
                 sum+=Arr[j];
                 if(sum==k)cnt++;
                
            }
            
        }
        return cnt;
    }
};
