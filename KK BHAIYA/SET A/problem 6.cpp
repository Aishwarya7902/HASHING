PROBLEM:  https://www.desiqna.in/part-7
Problem: Check if the following given array contains duplicate elements within k distance from each other.

Given an unsorted array that may contain duplicates. Also given a number k which is smaller than the size of the array, returns true if the array contains duplicates within k distance.



Example-1:

Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}

Output: false

All duplicates are more than k(3) distance away.

1...1(has a distance of 4)

2...2(has a distance of 4)

3...3 and 4...4 are similar 

Even if we find one duplicate number having a distance less than equal to k(<=k), we would return true.



Example-2:

Input: k = 3, arr[] = {1, 2, 3, 1, 4, 5}

Output: true

1 is repeated at distance 3(3<=k hence we return true)
  
  
  /*
  BRUTE FORCE
  Time complexity: O(k*n)
  Space complexity: O(1)
  */
#include <iostream>
using namespace std;

bool checkDuplicatesWithinK(int arr[], int n, int k)
{
    
 for(int i=0; i<n ;i++)//outer loop
	  {
	      for(int j=i+1; j<=i+k&&j<n; j++)//inner loop
	      {
	          if(arr[i]==arr[j]){   
	              if((j-i)<=k)return true;
	          }
	      }
	  }
	  return false;
}

int main() {
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (checkDuplicatesWithinK(arr, n, 3))
        cout << "Yes";
    else
        cout << "No";
}


/*METHOD 2 :
pseudo code:
1.make an unordered map
2.traverse array from left to right...then we will have two situations
A.if current element is already present in map then get its index from map 
calculate difference between current index and and index which we have fetched from map
->if the difference is greater than k then  update the position of current element in the map
->if difference is less than or equal to k then return true;

B.if the array element is not present in map then just  insert with its index


Time complexity: O(n)

Space complexity: O(n)
*/

bool helpduplicateAtK(int arr[],int n,int k){
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
       if(mp.find(arr[i])!=mp.end()){
           auto it=mp.find(arr[i]);
           int indx=it->second;
           if(i-indx<=k)return true;
           else
            mp[arr[i]]=i;
       }
       else
            mp[arr[i]]=i;
    }
    return false;
}
int main()
{
    int arr[]={1,2,3,4,1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(helpduplicateAtK(arr,n,3))
     cout<<"Yes";
    else
    cout<<"No";

    return 0;
}
  
