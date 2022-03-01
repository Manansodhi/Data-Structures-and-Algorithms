#include"bits/stdc++.h"
using namespace std;

vector<int> getVoters(int arr[], int n){
    sort(arr, arr+n);
    vector<int> voters;
    // for (int i = 0; i < n; ){
    //     int count = 0;
    //     int j = i;
    //     while (j < n && arr[j] == arr[i]){
    //         count++;
    //         j++;
    //     }
    //     if (count >=2){
    //         voters.push_back(arr[i]);
    //     }
    //     i = j;
    // }
    // return voters;
    map<int, int>mp;
    for (int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    for (auto i:mp){
        if (i.second > 1){
            voters.push_back(i.first);
        }
    }
    return voters;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int total_ele = n1 + n2 + n3;
    int arr[total_ele];
    for (int i = 0; i < total_ele; i++){
        cin >> arr[i];
    }
    
    vector<int> voters = getVoters(arr, total_ele) ;
    cout << voters.size() << endl;
    for (int i = 0; i < voters.size() ; i++){
        cout<< voters[i] << endl;
    }    

    return 0;
}