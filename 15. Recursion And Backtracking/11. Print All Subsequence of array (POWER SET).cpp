//TIME -->O(2^n * n) 
//Reason: O(2^n) for the outer for loop and O(n) for the inner for loop.
//Space Complexity: O(1)

vector<string> allPossibleStrings(string s){
	int n = s.length();
	vector<string>ans;
	for(int num=0; num < (1<<n); num++){
		string substring = "";
		for(int i=0;i<n;i++){
			//check if ith bit set or not 
			if(num & (1<<i)){
				substring += s[i];
			}
		}
		if(substring.length()>0)
			ans.push_back(substring);
	}
	return ans;
}