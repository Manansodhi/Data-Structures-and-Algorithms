
// Fumctional Recursion
// T.C --> O(N/2)
// S.C --> O(N/2)

int palindrone(int i, string s){
	int n=s.length();
	if(i>=n/2)
		return true;

	if(s[i] != s[n-i-1])
		return false;
	return palindrone(i+1);
}

int main(){
	return palindrone(0,str);
} 


