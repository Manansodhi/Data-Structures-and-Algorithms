#include<bits/stdc++.h>
using namespace std;

//sort() function

bool comparator(int a, int b) {
    return a > b;
}

//Bubble sort
bool compare(int a, int b) {
    return a < b;
}

void bubble_sort(int a[], int n, bool(&cmp)(int a, int b)) {

    //put n-1 large elements to the end
    for (int itr = 1; itr <= n - 1; itr++) {

        //pairwise swapping int the unsorted array
        for (int j = 0; j <= (n - itr - 1); j++) {
            if (cmp(a[j], a[j + 1])) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main() {
    int n, key;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    sort(a, a + n, greater<int>());
    sort(a, a + n, comparator);

    bubble_sort(a, n, compare);

    rotate(a, a + 2, a + n);
 
    //When we want to generate next lexiographic bigger number
    next_permutation(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    reverse(a + 2, a + n);


    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


return 0;
}