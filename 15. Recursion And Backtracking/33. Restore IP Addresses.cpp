/*
93. Restore IP Addresses

A valid IP address consists of exactly four integers separated by single dots. Each integer 
is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", 
"192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be 
formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. 
You may return the valid IP addresses in any order.

 
Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 
Constraints:
1 <= s.length <= 20
s consists of digits only.
*/

class Solution {
public:
    
    void getipAddress(vector<string> &temp, vector<string> &ip, string  &s, int idx){
        if(idx==s.length() && temp.size()==4){
            string validIP = temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3];
            ip.push_back(validIP);
            return;
        }
        string tempStr="";
        for(int i=idx;i<s.length() && temp.size()<4;i++){
            if(s[i]-'0'>9)
                continue;
            tempStr +=s[i];
            int tempInt = stoi(tempStr);
            if(tempInt>=0 && tempInt<=255){
                temp.push_back(tempStr);
                getipAddress(temp,ip,s,i+1);
                temp.pop_back();
            }
            if(tempInt<=0 || tempInt>255)
                break;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string>ip;
        vector<string>temp;
        getipAddress(temp,ip,s,0);
        return ip;
    }
};