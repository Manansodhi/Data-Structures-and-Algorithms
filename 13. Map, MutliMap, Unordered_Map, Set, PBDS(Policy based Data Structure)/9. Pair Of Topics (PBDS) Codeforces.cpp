#include<bit/stdc++.h>
#include<ext/pb_dsassoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/*
The next lecture in a high school requires two topics to be discussed. The i-th topic is interesting by ai units for the
teacher and by bi units for the students.
The pair of topics i and j (i<j) is called good if ai+aj>bi+bj (i.e. it is more interesting for the teacher).
Your task is to find the number of good pairs of topics.

Input
The first line of the input contains one integer n (2≤n≤2*105) — the number of topics.
The second line of the input contains n integers a1,a2,…,an (1≤ai≤10^9), where ai is the interestingness of the i-th topic for the teacher.
The third line of the input contains n integers b1,b2,…,bn (1≤bi≤10^9), where bi is the interestingness of the i-th topic for the students.

Output
Print one integer — the number of good pairs of topic.

Examples 1
input
5
4 8 2 6 2
4 5 4 1 3
output
7

Examples2
input
4
1 3 2 4
1 3 2 4
output
0
*/
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
	pbds st;
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		c[i] = a[i] - b[i];
	}

	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += st.size() - st.order_of_key({ -c[i], 100000000});
		st.insert({c[i], i});
	}
	cout << ans;
	return 0;
}
