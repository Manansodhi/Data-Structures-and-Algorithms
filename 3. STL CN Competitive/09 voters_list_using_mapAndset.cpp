#include"bits/stdc++.h"
using namespace std;



int main(){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int total_ele = n1 + n2 + n3;
    map<int, int> m;
    for (int i = 0; i < total_ele; i++){
        int x;
        cin >> x;
        m[x] = m[x]+1;
    }
    map<int, int>::iterator it;
    set<int> s;
   for (it = m.begin(); it != m.end(); it++){
       if (it->second > 1){
           s.insert(it->first);
       }
       cout << s.size() << endl;
	for(set<int>::iterator it1=s.begin();it1!=s.end();it1++)
	{
	    cout<<*it1<<endl;
	}
   }
    // for (int i = 0; i < voters.size() ; i++){
    //     cout<< voters[i]<< endl;
    // }    

    return 0;
}