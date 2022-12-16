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

/*
METHOD 2 : using hashing
TC: O(n)
SC:O(n)
Note:
->prefixSum  will store sum till current index
->count will store no of subarrays with sum==k
->map will store count of subarrays corresponding to a particular sum

intuition:
1->take a count variable
2->take a variable prefixSum to store sum till ith index
3-> take an unordered map named countSum which will store count of subarrys corresponding to a particular sum
for eg.
mp[5]=2 , it means there are two subarrays whose sum is 5.
4->run a loop from 0 to n-1
5->add nums[i] to prefixSum
6->if prefixsum==k ,count++;
7->if (prefixsum-k) is already present in map then it means there is some subarray jiske sum ko prefixSum me se minus karenge to jo resultant
sum aayega wo k ke barabar aayega.
hence ! we got a subarray whose sum is k....increase count as much times this subarray is present
8.mp[prefixSum]++; //as it can be used in future
9.return count
*/

class Solution{
    public:
    int findSubArraySum(int nums[], int N, int k)
    {
        // code here
        int count=0;
        int prefixSum=0;
        unordered_map<int,int>countSum;
        for(int i=0;i<N;i++){
            prefixSum+=nums[i];
             if(prefixSum==k)
              count++;
            
            if(countSum.find(prefixSum-k)!=countSum.end()){
                    count+=countSum[prefixSum-k];
                }
            
            countSum[prefixSum]++;
        }
     return count;   
    }
};


