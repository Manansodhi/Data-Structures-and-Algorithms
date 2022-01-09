#include<bits/stdc++.h>
using namespace std;

bool canDistributeEqually(int fruits){
	if (fruits % 11 == 1){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int fruits;
	cin >> fruits;
	int fullMoon = 0;
	while (!canDistributeEqually(fruits)){
		fullMoon++;
		fruits *= 2;
	}
	
	cout <<fullMoon << " " << fruits << endl;
	return 0;
	
}
