PROBLEM:https://leetcode.com/problems/4sum/
VIDEO:https://www.youtube.com/watch?v=4ggF3tXIAp0

/*
PSEUDO CODE:
1.sort
2.two for loops i,j
3.from j+1 .......low ,high loop
4.if target2=target-nums[i]-nums[j]
5.twoSum=nums[low]+nums[high]
6.if(twoSum<target2)
   low++;
  else if(twoSum>target2)
   high--;
   else{
      vector<int>quad(4,0);
      quad[0]=nums[i];
      quad[1]=nums[j];
     quad[2]=nums[low];
     quad[3]=nums[high];
     ans.push_back(quad);
     while(low<high && nums[low]==quad[2])low++;
     while(low<high && nums[high]==quad[3])high--;
     
7.processing j
       while(j+1<n && nums[j+1]==nums[j])j++;
8.processing i
      while(i+1<n && nums[i+1]==nums[i])i++;
9.return ans;                    
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        if(n==0)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               long long int target2 = 1LL*target - 1LL*nums[ i ]  -  1LL*nums[ j ];
                int low=j+1;
                int high=n-1;
                while(low<high){
                    int twoSum=nums[low]+nums[high];
                    if(twoSum<target2)
                     low++;
                    else if(twoSum>target2)
                     high--;
                    else{
                        vector<int>quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[low];
                        quad[3]=nums[high];
                       ans.push_back(quad);
                       while(low<high && nums[low]==quad[2])low++;
                       while(low<high && nums[high]==quad[3])high--;
                    }
                }
                //processing j
                while(j+1<n && nums[j+1]==nums[j])j++;
            }
            //processing i
                while(i+1<n && nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};
