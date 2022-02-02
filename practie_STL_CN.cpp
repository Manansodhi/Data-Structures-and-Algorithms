#include<bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(int * nums, int size) {
		if (size == 0) {
			return 0;
		}
		int n = size;
		int i(0), j(0);
		vector<int> cnt (0);
		cnt[nums[0]]++;
		int ans = nums[0];
		int ans2=0;
		while (j != n - 1) {
			if (cnt[nums[j + 1]] == 0) {
				j++;
				cnt[nums[j]]++;
				//ans+=num[j];
				ans = max(ans, ans+nums[j]);
				//ans2=ans;
			}
			else {
				cnt[nums[i]]--;
				ans = ans - nums[i];
				i++	;
			}
		}
		return ans;
	}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
int t;
cin>>t;

	while (t--) {
		int size;
		cin >> size;
		int arr[size];
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}

		int ans =maximumUniqueSubarray(arr,size);
		cout<< ans<< endl;
		//vector<int> ans = Longest_Consecutive_Sequence(arr, size);
		// for (auto i = ans.begin(); i != ans.end(); ++i) {
		// 	cout << *i << " ";
		// }
		// cout << endl;
		//delete[] arr;
	}



	return 0;
}