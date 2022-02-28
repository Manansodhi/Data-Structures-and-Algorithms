/*
Warm Reception

There is only one beauty parlour in the town CodingNinjasLand. The receptionist at the beauty parlor is flooded with appointment 
requests because the “Hakori” festival is round the corner and everyone wants to look good on it. She needs your help. The problem
is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. 
You have to tell the minimum number of chairs required such that none of the customers has to stand.

Input Format :
First line contains the number of customers that will come. Second line contains N space-separated integers which represent the 
arrival timings of the customer. Third line contains N space-separated integers which represent the departure timings
of the customer. Arrival and departure timings are given in 24-hour clock.

Constraints:
1<= N <= 100 Arrival and departure timings lie in the range [0000 to 2359]

Time Limit: 1 second

Output Format :
You have to print the minimum number of chairs required such that no customer has to wait standing. 

Sample Test Cases:
Sample Input 1 :
5
900 1000 1100 1030 1600
1900 1300 1130 1130 1800

Sample Output 1:
4
Explanation:
4 because at 1100 hours, we will have maximum number of customers at the shop, throughout
 the day. And that maximum number is 4. 
 
*/

#include<bits/stdc++.h>
using namespace std;

class detail
{
public:
    int time;
    bool status;
    
};


bool mysort(detail a, detail b){
    return(a.time < b.time);
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    int n;
    cin>>n;
    //Arrival
    vector<detail> people;
    for (int i = 0; i < n; ++i)
    {
        int temp_time;
        cin>>temp_time;
        detail temp;
        temp.time = temp_time;
        temp.status = 1;
        people.push_back(temp);
    }

//Departure
    for (int i = 0; i < n; ++i)
    {
        int temp_time;
        cin>>temp_time;
        detail temp;
        temp.time = temp_time;
        temp.status = 0;
        people.push_back(temp);
    }

//Sorting

    sort(people.begin(), people.end(), mysort);
    

    int ans = 0;
    int count = 0;

    vector<detail> :: iterator it = people.begin();

    for (int i = 0; i < people.size(); ++i)
    {
        if (people.at(i).status == 1)
        {
            count++;
        }else{
            count--;
        }
        ans = max(ans, count);
    }

    cout << ans << '\n';


    return 0 ; 



}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int dep[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>dep[i];                                
    }
    
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i=1,j=0chairsNeeded=0,ans=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            chairsNeeded++;
            i++;
            ans=max(ans,chairsNeeded);
        }
        else{
            j++;
            chairsNeeded--;
        }
    }
    
    cout<<ans<<'\n';
    return 0;
}
