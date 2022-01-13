#include<bits/stdc++.h>
using namespace std;


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


// //DISTRUB FRUITS EQUALLY
// bool canDistributeEqually(int fruits){
// 	if ((fruits % 11) == 1){
// 		return true;
// 	}
// 	else{
// 		return false;
// 	}
// }



// //LEAD GAME
// void LeadGame(int n){
// 	int cs1 = 0, cs2 = 0;
// 	int max_lead = 0, max_lead_player = 1;

// 	while (n--){
// 		int s1, s2;
// 		cin >>s1 >>s2 ;
// 		cs1 += s1;
// 		cs2 += s2;
// 		int curr_lead = 0;
// 		int curr_lead_player = 1;
// 		if (cs1 >= cs2){
// 			curr_lead = cs1- cs2;
// 		}
// 		else{
// 			curr_lead = cs2 - cs1;
// 			curr_lead_player = 2;
// 		}
// 		if (curr_lead > max_lead){
// 			max_lead = curr_lead;
// 			max_lead_player = curr_lead_player;
// 		}
// 	}
// 	cout << "Max Lead Player : " << max_lead_player <<" Max Lead : " << max_lead << endl;
// }


// //SUM ALL ELEMENTS ON BOTH DIAGONAL AND ALL BOUNDARY ELEMENTS ONLY ONCE

// void sumDiagonalBoundaryElements(int n){
// 	int arr[n][n];
// 	int sum = 0;
// 	for (int i = 0; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 			cin >> arr[i][j];
// 		}
// 	}

// 	for (int i = 0,j = 0; i < n; i++,j++){
// 			sum += arr[i][j];
// 		}

// 	for(int i = 0,j = n-1; i < n; i++,j--){
// 		sum += arr[i][j];
// 	}

// 	for (int i = 1; i < n-1; i++){
// 		sum += arr[0][i];
// 		sum += arr[i][0];
// 		sum += arr[n-1][i];
// 		sum += arr[i][n-1];
// 	}


// 	    if (n % 2 != 0){
//         sum -= arr[n/2][n/2];
//     }
//     cout << sum << endl;

// }


// //TARGET MARBLES
// void targetMarble(int * value, int noMarbles, int target){
// 	int start = 0, end = 0, curr_target = value[0];
// 	while(start < noMarbles && end < noMarbles){
// 		if(curr_target < target){
// 			end++;
// 			curr_target += value[end];
// 		}
// 		else if(curr_target > target){
// 			curr_target -= value[start];
// 			start++;
// 		}
// 		else{
// 			cout << "True" << endl;
// 			for (int i = start; i <= end; i++){
// 				cout << value[i] <<" ";
// 			}
// 			return;
// 		}
// 	}
// 	cout << "false" << endl;
// }


//OSCILATING PRICES OF CHAKRI
int maxProfit(int arr[], int arr_size){
	int max_diff = arr[1] - arr[0];
	int min_element = arr[0];
	for (int i = 1; i < arr_size; i++) {
		if (arr[i] - min_element > max_diff) {
			max_diff = arr[i] - min_element;
		}
		if (arr[i] < min_element) {
			min_element = arr[i];
		}
	}
	return max_diff;
}




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
// 	for (int i = 0; i < n; i++) {
// 		arr[i] = new int[n];
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 		}
// 	}
// 	for (int col = 0; col < n; col++) {
// 		if ((col % 2) == 0) {
// 			for (int row = 0; row < n; row++) {
// 				cout << arr[row][col] << " " ;
// 			}
// 		}
// 		else {
// 			for (int row = n - 1; row > 0; row--) {
// 				cout << arr[row][col] << " ";
// 			}
// 		}
// 	}
// 	for (int i = 0; i < n; i++) {
// 		delete arr[i];
// 	}
// 	delete [] arr;


// //LEAD GAME
// 	int n;
// 	cin >> n;
// 	LeadGame(n);


// //SUM OF ELEMENTS OM BOTH DIAGONAL AND ALL BOUNDARY ELEMENTS ONLY ONCE
// 	int n;
// 	cin >> n;
// 	sumDiagonalBoundaryElements(n);


// //TARGET MARBLES
// 	int noMarbles, target;
// 	cin >> noMarbles >> target;
// 	int value[noMarbles];
// 	for (int i = 0; i < noMarbles; i++) {
// 		cin >> value[i];
// 	}
// 	targetMarble(value, noMarbles, target);

// //TARGET MARBLES
// 	int n, t;
// 	cin >> n >> t;
// 	int* arr = new int[n];
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> arr[i];
// 	}
// 	for (int i = 0; i < n; i++)
// 	{

// 		int sum = 0;
// 		int number = i;
// 		vector<int>v;

// 		while ((sum != t) && (number < n))
// 		{
// 			sum += arr[number];
// 			v.push_back(arr[number]);
// 			number += 1;
// 		}
// 		if (sum == t)
// 		{
// 			cout << "true" << endl;
// 			for (int j = 0; j < v.size(); j++)
// 			{
// 				cout << v[j] << " ";
// 			}
// 			return 0;
// 		}
// 	}
// 	cout << "false";
// }

// //PRE4
// 	int noVillagers;
// 	int noTeams = 0, leftVillagers = 0; 
// 	cin >> noVillagers;
// 	int player[noVillagers];
// 	for (int i = 0; i < noVillagers; i++){
// 		cin >> player[i];
// 	}
// 	for (int i = 0,end = noVillagers; i < (noVillagers/2); i++,end--){
// 		noTeams = ((player[i]+player[end-1])/10);
// 		leftVillagers = ((player[i]+player[end-1])%10);
// 		cout << "No of Teams formed : " << noTeams <<" " << "No of left Villagers : " << leftVillagers << endl;
// 	}


//OSCILATING PRICES OF CHAKRI
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << maxProfit(arr, n) << endl;

 	return 0;
}