
//Using Binary Search
void min_pair(vector<int>a1, vector<int> a2) {
	sort(a2.begin(), a2.end());

	int p1, p2, diff = INT_MAX;

	//iterate over a1 and look for closes elements in the a2
	for (int x : a1) {
		auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin();

		//left lb>=1 so to avoid that it does not take lb-1 out of array when lb=0
		/*
			a1={1,5,10,20,3} a2_Sorted= {15,17,26,,134,135}
			x=20 lower_bound(20)-> lb-1=1(index of 17), lb=2(index of 26)
			x-a2[lb-1] => 20-a2[1]=20-17==>3<INT_MAX ==> diff = 3, p1=20, p2=17
		*/
		if (lb >= 1 and x - a2[lb - 1] < diff) {
			diff = x - a2[lb - 1];
			p1 = x;
			p2 = a2[lb - 1];
		}

		//greater on right
		if (lb != a2.size() and a2[lb] - x < diff) {
			diff = a2[lb] - x;
			p1 = x;
			p2 = a2[lb];
		}
	}
	cout << "Min Pair " << p1 << " and " << p2 << endl;
	return;
}

//Using 2 pointer

#define ll long long int

ll MinDif(vector <ll> v1, vector <ll> v2, ll m, ll n) {
	ll i = 0;
	ll j = 0;
	ll a = 0, b = 0;
	ll min = INT_MAX;
	while (i < m && j < n) {
		if (abs(v1[i] - v2[j]) < min) {
			min = abs(v1[i] - v2[j]);
			a = v1[i];
			b = v2[j];
		}
		if (v1[i] < v2[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	cout << a << "-" << b << "=";
	return min;
}
int main() {
	ll m, n; cin >> m >> n;
	vector <ll> v1, v2;
	for (ll i = 0; i < m; i++) {
		ll a; cin >> a;
		v1.push_back(a);
	}
	for (ll i = 0; i < n; i++) {
		ll a; cin >> a;
		v2.push_back(a);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	cout << MinDif(v1, v2, m, n);
	// your code goes here
	return 0;
}
