PROBLEM: https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values3719/1

VIDEO:https://youtu.be/hCGUty76A6M

/*
METHOD 1 (OWN)
TC:
SC:
*/

class Solution{
  public:
    vector<int> PosNegPair(int a[], int n) {
        vector<int>ans;
        unordered_map<int,int>mp;
        sort(a,a+n); //array ko sort kar do
        for(int i=0;i<n;i++){
            if(mp[-a[i]]>=1){ 
                /*agr current elem ka negative map 
            me present hai and uska count 1 ya 1 se jyada hai then us element ke 
            corresponding -ve and +ve ko ans me dal do
            and then map me jo opposite element tha uske count ko
            ek less kar do
            */
            
                int key=abs(a[i]);
                ans.push_back(-key);
                ans.push_back(key);
                //int oppo=-a[i];
                mp[-a[i]]--;
            }
            else{
                //agr given elem ka opposite map me ni hai to given elem ko map me dal do
                mp[a[i]]++;
            }
        }
        return ans;
    }
};
