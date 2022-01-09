#include"bits/stdc++.h"
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stfdin);
	freopen("output.txt", "w", stdout);
#endif

	int rounds;
	cin >> rounds;
	int max_lead_player = 1;
	int sum2 = 0, sum1 = 0;
	int max_lead = 0;


	while (rounds--) {
		int player1, player2;
		cin >> player1 >> player2;
		sum1 += player1;
		sum2 += player2;

		int curr_lead = 0;
		int curr_lead_player = 1;

		if (sum1 >= sum2) {
			curr_lead = (sum1 - sum2);
		}
		else {
			curr_lead_player = 2;
			curr_lead = sum2 - sum1;
		}

		if (curr_lead > max_lead) {
			max_lead = curr_lead;
			max_lead_player = curr_lead_player;
		}
	}

	cout << max_lead_player << " " << max_lead << endl;

	return 0;
}