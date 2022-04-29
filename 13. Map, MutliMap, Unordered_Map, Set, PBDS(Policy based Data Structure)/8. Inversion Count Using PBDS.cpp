#include<bit/stdc++.h>
#include<ext/pb_dsassoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//TIME:- O(NLogN)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
	pbds st;
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int inversion_count = 0;
	for (int i = 0; i < n; i++) {
		inversion_count += st.size() - st.order_of_key(arr[i]);
		st.insert(arr[i]);
	}
}