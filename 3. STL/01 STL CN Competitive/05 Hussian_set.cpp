#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif    
    int n, m;
    cin >> n >> m;
    ll arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    queue<ll> q;
    int count_query = 0; 
    int end_pointer = n-1;
    while (m--){
        int curr_query;
        cin >> curr_query;
        ll ans ;
        for ( ; count_query < curr_query; count_query++){
            if (end_pointer >=0 &&(q.empty() || (arr[end_pointer] >= q.front()))){
                ans = arr[end_pointer];
                end_pointer --;
            }
            else{
                ans = q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout << ans << endl;
    }
    return 0;
} 


