#include<bits/stdc++.h>
using namespace std;

int areaOf2Rectangles(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	int a1 = (x2-x1)*(y2-y1);
	int a2 = (x4-x3)*(y4-y3);
	int right = min(x2,x4);
	int left = max(x1,x3);
	int top = min(y4,y2);
	int bottom = max(y1,y3);
	int A_intersection = 0;

	if ((left < right) && (bottom < top)){
		A_intersection = (right-left)*(top-bottom);
	}
	int ans = a1+a2-A_intersection;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1 >>y1 >>x2 >>y2 >>x3 >>y3 >>x4 >>y4;
	cout<< areaOf2Rectangles(x1,y1,x2,y2,x3,y3,x4,y4) << endl;
	return 0;
}