PROBLEM: https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values3719/1

VIDEO(PRINCE BHAIYA):https://youtu.be/hCGUty76A6M

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

/*
METHOD 2:
TC:
SC:
*/

class Solution{
  public:
    vector<int> PosNegPair(int a[], int n) {
       vector<int>v,ans;
       map<int,int>mp;
       for(int i=0;i<n;i++){
           if(a[i]<0)
            v.push_back(a[i]);
           else
            mp[a[i]]++;
       }
       sort(v.begin(),v.end());
       for(int i=v.size()-1;i>=0;i--){
           int data=abs(v[i]);
           if(mp[data]>0){
               ans.push_back(v[i]);
               ans.push_back(data);
               mp[data]--;
           }
       }
       return ans;
    }
};

