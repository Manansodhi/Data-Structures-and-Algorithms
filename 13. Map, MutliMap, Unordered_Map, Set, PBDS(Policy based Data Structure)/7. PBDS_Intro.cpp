#include<bit/stdc++.h>
#include<ext/pb_dsassoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
	pbds st;

	/*
	if want to male duplicate in pbds so we can have to make pair<int, int> amd first int will contain value that can be same but second int will always unique number and it is index
	*/

	st.insert(1);
	st.insert(10);
	st.insert(2);
	st.insert(3);
	st.insert(40);
	st.insert(4);
	st.insert(21);
	st.insert(11);
	for (int i = 0; i < st.size(); i++) {
		cout << i << " " << *st.find_by_order(i) << endl;
	}


	return 0;
}