#include<bits/stdc++.h>
using namespace std;

//LEAD GAME
void LeadGame(int n){
	int cs1 = 0, cs2 = 0;
	int max_lead = 0, max_lead_player = 1;

	while (n--){
		int s1, s2;
		cin >>s1 >>s2 ;
		cs1 += s1;
		cs2 += s2;
		int curr_lead = 0;
		int curr_lead_player = 1;
		if (cs1 >= cs2){
			curr_lead = cs1- cs2;
		}
		else{
			curr_lead = cs2 - cs1;
			curr_lead_player = 2;
		}
		if (curr_lead > max_lead){
			max_lead = curr_lead;
			max_lead_player = curr_lead_player;
		}
	}
	cout << "Max Lead Player : " << max_lead_player <<" Max Lead : " << max_lead << endl; 
}



// //DISTRUB FRUITS EQUALLY
// bool canDistributeEqually(int fruits){
// 	if ((fruits % 11) == 1){
// 		return true;
// 	}
// 	else{
// 		return false;
// 	}
// }


// //AREA OF 2 INTERSECTD RECTANGLE
// int areaOf2Rectangles(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
// 	int a1 = (x2-x1)*(y2-y1);
// 	int a2 = (x4-x3)*(y4-y3);
// 	int right = min(x2,x4);
// 	int left = max(x1,x3);
// 	int top = min(y4,y2);
// 	int bottom = max(y1,y3);
// 	int A_intersection = 0;

// 	if ((left < right) && (bottom < top)){
// 		A_intersection = (right-left)*(top-bottom);
// 	}
// 	int ans = a1+a2-A_intersection;
// 	return ans;
// }

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int x1,y1,x2,y2,x3,y3,x4,y4;
	// cin>>x1 >>y1 >>x2 >>y2 >>x3 >>y3 >>x4 >>y4;
	// cout<< areaOf2Rectangles(x1,y1,x2,y2,x3,y3,x4,y4) << endl;
	

	// int fruits;
	// cin >> fruits;
	// int fullMoons = 0;
	// while(!canDistributeEqually(fruits)){
	// 	fullMoons++;
	// 	fruits *=2;
	// }
	// cout << "No of Full Moons " << fullMoons << endl;


// //ZIG ZAG PATTERN
// 	int n;
// 	cin >> n;
// 	int ** arr = new int *[n];
// 	for (int i = 0; i < n; i++){
// 		arr[i] = new int[n];
// 		for (int j = 0; j < n; j++){
// 			cin >> arr[i][j];
// 		}
// 	}
// 	for(int col = 0; col < n; col++){
// 		if ((col % 2) == 0){
// 			for (int row = 0; row < n; row++){
// 				cout << arr[row][col] << " " ;
// 			}
// 		}
// 		else{
// 			for (int row = n-1; row > 0; row--){
// 				cout << arr[row][col] << " ";
// 			}
// 		}
// 	}
// 	for (int i = 0; i < n; i++){
// 		delete arr[i];
// 	}
// 	delete [] arr;

	int n;
	cin >> n;
	LeadGame(n);

 	return 0;
}