PROBLEM: https://leetcode.com/problems/find-common-characters/description/

/*
Intution/Algorithm/pseudo code:
1.if we can track the minimum count of each character which is present in every single string then we can use that to make ans.

2.what next..........?????????????

3.take a hashmap1( instead of hashmap we can use a vector of length 26 ,since we have to deal with lowecase only)
in which we will update our minimum count corresponding to each character

(NOTE: This is similar to the variable mini ,which we used while calculating minimum in  the array)

4.in hash1 vector store the frequency of each character  corresponding to the string stored at index 0.

5.run a loop from 1->size of words
for current index i ,store the count of each character of words[i] in hash2 vector

-> now run a loop  from 1 to 26 and update hash1[i]=min(hash1[i],hash2[i]);
and do hash2[i]=0;

6.now after the loop hash1 has stored the minimum count for each character.

7.now run a loop

from 1->size of hash1
make a string corresponding to the count of each character in hash1 and push that string in ans

8. return ans


Tc: o(n) ,where n is total character
Sc: o(1) as we used two fixed size vector

*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
      vector<string>ans;//to store our answer
      vector<int>hash1(26,0);
      vector<int>hash2(26,0);
      for(auto ch:words[0]){
          hash1[ch-'a']++;
      }
      for(int i=1;i<words.size();i++){
         for(auto ch:words[i]){
             hash2[ch-'a']++;
         }
         for(int i=0;i<26;i++){
             hash1[i]=min(hash1[i],hash2[i]);
             hash2[i]=0;
         } 
      }
    for(int i=0;i<hash1.size();i++){
        if(hash1[i]>0){
            int count=hash1[i];
            while(count--){
                char x=i+'a';
                string s;
                s=x;
                ans.push_back(s);
            }
        }
    }
    return ans;
    }
};
