PROBLEM:https://leetcode.com/problems/max-points-on-a-line/description/
BLOG:https://leetcode.com/problems/max-points-on-a-line/solutions/1739295/simple-c-solution-2-approaches-brute-force-as-well-using-using-hashmap-16ms/?orderBy=most_votes&languageTags=cpp

/*
METHOD 1:
TC:O(n^3)
SC:
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
     if(points.size()<=2)return points.size();
     int res=0;
     int n=points.size();
     for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             int x1=points[i][0];
             int x2=points[j][0];
             int y1=points[i][1];
             int y2=points[j][1];
             int total=2;
             for(int k=0;k<n && k!=i && k!=j;k++){
                int x=points[k][0];
                int y=points[k][1];
                if((y2-y1)*(x-x1)==(y-y1)*(x2-x1))
                 total++;
             }
             res=max(res,total);
         }
     }
     return res;   
    }
};

/*METHOD 2

using hashmap
Time Complexity : O(n^2)
SC:O(n)
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
     if(points.size()<=2)return points.size();
     int res=0;
     int n=points.size();
     for(int i=0;i<n;i++){
         unordered_map<double,int>mp;
         double slope=0.0;
         int duplicate=0;
         for(int j=0;j<n;j++){
             int x1=points[i][0];
             int x2=points[j][0];
             int y1=points[i][1];
             int y2=points[j][1];
             int dx=x2-x1;
             int dy=y2-y1;
             if(dx==0 && dy==0)
             {
              duplicate++;
              continue;
             }
             if(dx!=0){
                 slope=dy*1.0/dx;
             }
             else
              slope=INT_MAX;

          mp[slope]++;   
         }
         if(mp.size()==0)
          res=duplicate;
        else{
            for(auto it:mp){
                res=max(res,it.second+duplicate);
            }
        }
     }
     return res;   
    }
};
