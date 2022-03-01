#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a <= b;
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins) / sizeof(int);
    int money = 208;
    while (money > 0) {
        //As lower_bound() function gives that element that is >= key so for 168 we will we get 200 but we
        //donot want this so to avoid this we will make our own comparator function to reverse the comparison <=

        //int lb = lower_bound(coins, coins+n, money) - coins -1;
        // this above line will fail for money=100 it will return coin of 50 instead of 100. so we should write
        our comparator function

        int lb = lower_bound(coins, coins + n, money, compare) - coins - 1;
        int m = coins[lb];
        cout << m << " ";
        money -= m;
    }

    return 0;
}