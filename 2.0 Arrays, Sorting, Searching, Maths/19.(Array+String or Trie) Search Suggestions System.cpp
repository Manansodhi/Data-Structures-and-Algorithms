/*
1268. Search Suggestions System

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 

Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
*/

class Solution {
public:
//     vector<vector<string>> suggestedProducts(vector<string>& pr, string sw) {
//         vector<vector<string>> ans;
//         sort(pr.begin(),pr.end());
//         for(int i=0; i < sw.size();i++){
//             int len=i+1;
//             vector<string> ds;
//             string sub_str=sw.substr(0,i+1);
//             int count=0;
//             for(int j=0; j<pr.size();j++){
//                 if(pr[j].find(sub_str)==0 && count<3 ){
//                     ds.push_back(pr[j]);
//                     count++;
                    
//                 }
//             }
            
//                 ans.push_back(ds);
//         }
//         return ans;
        
//     }
    
    vector<vector<string>> suggestedProducts(vector<string> &products,
                                             string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        int start, bsStart = 0, n=products.size();
        string prefix;
        for (char &c : searchWord) {
            prefix += c;

            start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();

            result.push_back({});
            for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++)
                result.back().push_back(products[i]);

            bsStart = start;
        }
        return result;
    }

    
};