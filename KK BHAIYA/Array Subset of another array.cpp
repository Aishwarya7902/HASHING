PROBLEM: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


/*
tc:o(m+n)
sc:o(n)
*/

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>mp;
    //traverse in a1 and get all the elments registred in map mp
    for(int i=0;i<n;i++){
       mp[a1[i]]++; 
    }
    //now check if all the elements of a2 are present in a1 or not
    for(int i=0;i<m;i++){
        if(mp[a2[i]]==0)
         return "No";
         mp[a2[i]]--;
    }
    return "Yes";
}
