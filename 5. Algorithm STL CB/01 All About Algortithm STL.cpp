#include<bits/stdc++.h>
using namespace std;


int main() {
    int arr[] = {1, 10, 11, 9, 100};
    int n = sizeof(arr) / sizeof(int);
    int key = 13;

    //Find Function
    // when key is not present in the array find fumc will return the pointer to the last position of array
    auto it = find(arr, arr + n, key); //find function returns pointer to that location
    cout << it << endl; // this will return the addres of key

    //by subracting the starting element address with cyrrent element address we will get the number of
    //elements between element
    int index = it - arr;
    cout << index << endl;
    if (index == n) {
        cout << key << " Not found" << endl;
    }
    else {
        cout << key << " Present at index " << index << endl;
    }



    //BINARY SEACRH  Time :- O(Log N)
    int arr[] = {20, 30, 40, 40, 40, 50, 100};
    int n = sizeof(arr) / sizeof(int);
    int key = 30;
    bool present = binary_search(arr, arr + n, key); //binary_search() will return either true/false
    if (present) {
        cout << "presemt" << endl;
    }
    else {
        cout << "absent!" << endl;
    }


    //upper_bound()   lower_bound()  function to get index of element
    int arr[] = {20, 30, 40, 40, 40, 50, 100};
    int n = sizeof(arr) / sizeof(int);
    int key = 40;

    //int * lb becoz lower_bound() will return address
    // it will return the address of first element >= key
    auto lb = lower_bound(arr, arr + n, 40);
    cout << (lb - arr) << endl; //2

    // it will return the address of first element > key
    auto ub = upper_bound(arr, arr + n, 40);
    cout << (ub - arr) << endl; //5

    //Upper_bound - lower_bound -> gives the frequency of element
    // if we want to find the frequency of element in sorted array we do that by subtracting ub-lb
    cout << "occurance frequency of 40 is " << (ub - lb) << endl;

    // if we want to find the lower_bound of 41 then it will return next greater element then 41 that is 50
    //and it's index is 5 and upper bound will also be 5 and ub-lb will be zero becoz it is not present in
    //array
    
    return 0;

}


//sort() function

bool compare(int a, int b) {
    return a < b;
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
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;



    //Bubble sort
    bool compare(int a, int b) {
        return a > b;
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

        bubble_sort(a, n, compare);

        rotate(a, a + 2, a + n);

        next_permutation(a, a + n);

        reverse(a + 2, a + n);


        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;



        return 0;
    }