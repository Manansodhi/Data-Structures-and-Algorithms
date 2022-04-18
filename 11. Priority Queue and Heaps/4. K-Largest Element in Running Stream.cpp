#include<bits/stdc++.h>
using namespace std;

void query_point(priority_queue<int, vector<int>, greater<int> > pq) {
	while(!pq.empty()) {
		cout << pq.top() << ",";
		pq.pop();
	}
	cout << endl;
}

// input 1 2 3 4 -1 5 9 10 -1 12 15 8 6 -1
// output
// 2,3,4
// 5,9,10
// 10,12,15

int main() {
	int key = 3;
	int no, cs = 0; //cs-> this will ensure the max limit of the heap size
	priority_queue<int, vector<int>, greater<int> >pq;
	while (scanf("%d", &no) != EOF) {
		if (no == -1) {
			//print the k-largest element as query point has occured from the elements before -1
			query_point(pq);
		}
		else if (cs < key) {
			//means current size of heap is less than k push number from running stream ans increment current size of heap
			pq.push(no);
			cs++;
		}
		else {
			if (no > pq.top()) {
				//if number in running stream is greater than the number at the top of heap
				pq.pop();
				pq.push(no);
			}
		}
	}
	return 0;
}