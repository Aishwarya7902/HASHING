PROBLEM: https://www.interviewbit.com/problems/subarray-with-given-xor/
VIDEO:(striver bhaiya) https://www.youtube.com/watch?v=lO9R5CaGRPY

/*
BRUTE FORCE
TC:O(n^2)
SC:O(1)
PSEUDO CODE:
1.generate all subarrays and calculate xorr of that subarray and if xorr value==k
cnt++

note:for generating all the subarrays is gonna take u a o(n^2) hence it is a naive solution
*/
int solve(vector<int> &A, int B) {
    int n1=A.size();
    int cnt=0;
    for(int i=0;i<n1;i++){
        int xorr=0;
        for(int j=i;j<n1;j++){
            xorr=xorr^A[j];
            if(xorr==B)cnt++;
        }
    }
    return cnt;
}

/*
METHOD 2:
using hashing
tc:o(n)
sc:o(n)
pseudo code 
1.in this we will do something similar to what we did in no of subarrays with sum equal to k
Note:
->xorr variable will store xor till current index
->count will store no of subarrays with xor==k
->map will store count of subarrays corresponding to a particular xor
intuition:
1->take a count variable
2->take a variable xorr to store xor till ith index
3-> take an unordered map named XorrTillIndx which will store count of subarrys corresponding to a particular xor
for eg.
mp[5]=2 , it means there are two subarrays whose xor is 5.
4->run a loop from 0 to n-1
5->take xor of nums[i] with xorr variable
6->if xorr==k ,count++;
7->if (xorr-k) is already present in map then it means there is some subarray jiske xor  ko xorr variable ke sath lenge  to jo resultant
xor aayega wo k ke barabar aayega.
hence ! we got a subarray whose xor is k....increase count as much times this subarray is present
8.mp[xorr]++; //as it can be used in future
9.return count
*/

int solve(vector<int> &A, int B) {
    int cnt=0;
    int xorr=0;
    unordered_map<int,int>XorrTillIndx;
    for(auto it:A){
        xorr=xorr^it;
        if(xorr==B){
            cnt++;
        }
        if(XorrTillIndx.find(xorr^B)!=XorrTillIndx.end()){
            cnt+=XorrTillIndx[xorr^B];
        }
        XorrTillIndx[xorr]++;
    }
   return cnt; 
}
