PROBLEM: https://leetcode.com/problems/first-unique-character-in-a-string/description/

/*
USING HASHING 
PSEUDO CODE:

1.Take an unordered map
2.traverse in string and store frequency of each character in map
3.now traverse in string and see if the frequency stored  in map of that particular character is 1,if yes simply return that index
4.at end if there is no element which is non repeating ...return -1 (as said in the question)

TC:O(N)
SC:O(N)
*/

class Solution {
public:
    int firstUniqChar(string s) {
     unordered_map<char,int>mp;
     //traverse in s to get freq of each character
     for(auto x:s){
       mp[x]++;  
     } 
     //traverse in s and check in map if freq is 1..if yes then simply return that index
     for(int i=0;i<s.size();i++){
        if(mp[s[i]]==1)
         return i; 
     } 
     return -1; 
    }
};
