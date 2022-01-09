#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("bendin.txt","r",stdin);
	freopen("bendout.txt","rw",stdout);
	int x1, x2, x3, x4, y1, y2, y3, y4;
	cin >>x1 >>x2 >>x3 >>x4 >>y1 >>y2 >>y3 >>y4;
	int A1 = (x2 - x1) * (y2 - y1);
	int A2 = (x4 - x3) * (y4- y3);
	
	int left = max(x1, x3);
	int right = min(x2, x4);
	int bottom = max(y1, y3);
	int top = min(y2, y4);
	
	int A_intr = 0;
	
	if ((left < right) && (bottom < top)){
		A_intr = ((right - left) * (top - bottom));
	}
	int ans = A1 + A2 - A_intr;
	cout << ans << endl;
	return 0;
	
}
