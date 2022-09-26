/*
890. Find and Replace Pattern

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. 
You may return the answer in any order.
A word matches the pattern if there exists a permutation of letters p so that after replacing every
letter x in the pattern with p(x), we get the desired word.
Recall that a permutation of letters is a bijection from letters to letters: every letter maps to
another letter, and no two letters map to the same letter.

 

Example 1:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]

Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map 
to the same letter.

Example 2:
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
 
Constraints:
1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.

*/


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      vector<string>ans;
      for(int i=0;i<words.size();i++){
        int flag=1;
        map<char,char>m1,m2;
        for(int j=0;j<words[i].size();j++){
          //words--> mee  pattern[]--> abb
          auto it1 = m1.find(pattern[j]);
          auto it2 = m2.find(words[i][j]);
          
          if(it1 == m1.end()){
            m1.insert({pattern[j], words[i][j] });
          }
          else{
            if(it1->second != words[i][j]){
              flag=0;
              break;
            }
          }
          
          if(it2 == m2.end()){
            m2.insert({ words[i][j] ,pattern[j]});
          }
          else{
            if(it2->second != pattern[j]){
              flag=0;
              break;
            }
          }
        }
        if(flag)
          ans.push_back(words[i]);
      }
      return ans;
    }
};



// ["abc ","  deq "," mee "," aqq "," dkd "," ccc"]
//   123     123      122     122      121     111
// PATTERN
//    "abb"
//     122
// So, we can clearly see 2 words have same pattern that is 122


class Solution {
public:
    
    vector<int> found_Pattern(string pattern)
    {
	   // if string is empty return empty vector.
        if(pattern.size() == 0)
            return {};
        
        vector<int> v;
		
		// ind variable for keeping track of unique characters
        int ind = 0;
		
        unordered_map<char,int> mp;
        for(int i = 0; i<pattern.size(); ++i)
        {
			// if character not present in map, insert the char with an index,
			// increment index because for next unique character the index should be differnt.
           if(mp.find(pattern[i]) == mp.end())
           {
               mp.insert({pattern[i],ind++});
			   // also  push the index to v(numeric  pattern vector)
			   // mp[pattern[i]] gives the key to that character, here key is ind(which we are giving 
			   //to every unique character)
               v.push_back(mp[pattern[i]]);
           }
            else
            {
				// if char is already in map than push index mapped to that character into the vector
                v.push_back(mp[pattern[i]]);
            }
        }
		// return numeric pattern
        return v;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       
		// store numeric patten of Pattern string in v
        vector<int> v = found_Pattern(pattern);
        
        int n = words.size();
        vector<string> ans;
        
		// iterating and comparing pattern of each word with v(numeric pattern of Pattern)
        for(int i = 0; i<n; ++i)
        {
            vector<int> pattern_word = found_Pattern(words[i]);
            
			// if matched add words[i] to answer vector
            if(v == pattern_word)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};

class Solution {
public:
    string getPattern(string pattern){
        
        string ans;
        int j=0;
        
        map<char,char> mp;
        
        for(int i=0;i<pattern.size();i++){
            if(mp.find(pattern[i])==mp.end()){
                mp[pattern[i]]='a'+j; 
                j++;
            }
            
            ans.push_back(mp[pattern[i]]);
            
        }
        
        return ans;
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        string pat=getPattern(pattern);
        
        vector<string> ans;
        
        for(int i=0;i<words.size();i++){
            string p=getPattern(words[i]);
            if(p==pat){
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};