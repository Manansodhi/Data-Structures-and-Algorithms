#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    return a <= b;
}

int main(){
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins)/sizeof(int);
    int money = 208;
    while (money > 0){
        int lb = lower_bound(coins, coins+n, money) - coins -1;
        int m = coins[lb];
        cout <<m <<" ";
        money -= m;
    }

    return 0;
}