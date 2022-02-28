#include"bits/stdc++.h"
using namespace std;

char getchar(int i){
    return (char)(i+97);
}

void PrintPalindromeString(string s){
    map<char, vector<int> >indexesMap;
    for (int i = 0; i < s.length(); i++){
        indexesMap[s[i]].push_back(i); 
        //storing the indexes of each character ki jase indexesMap[s[i]] se ek charcter milega 
        //phir humne uske sath ek vector of int bnaya h esme uska index ko push_back kar rahe h
    }

    int odd_freq_count = 0;
    for (int i = 0; i < 26; i++){//ye wala loop constant time lega becoz fixed time chalega N per dependent nahi h
        // ye loop uske liye chalya h ki jo hmare map m jitne bhi character h max 26 m se koi bhi
        // ho sakta h toh har character per ja kar odd_frequency_count nikal rahe h 
        if ((indexesMap[getchar(i)]).size() % 2 != 0 ){
            /*esme kya ho raha h ki jase ye loop har 26 ki character ki liye chalega becoz string m koi se bhi character ho 
            skte h purre 26 charcter m se toh loop jab chala i=0 ke liye getchar(0) -> a la kar dega fir indexMap[a].size() 
            us character 'a' ki frequency nikalegi uske indexes ki agar voh  odd hua toh fir usko increment kardge 
            */
            odd_freq_count ++;
        }
    }
    if (odd_freq_count >= 2){
        cout << -1 ;
        return;
    }

    int ans[s.length()];
    int start = 0;
    int end = s.length()-1;
    for (int i = 0; i < 26; i++){
        char curr_char = getchar(i);
        for (int j = 0; j < indexesMap[curr_char].size(); j+=2){

            if((indexesMap[curr_char].size()-j) == 1){
                // ab jo ye if condition h voh uske pata lgane ke liye h ki agr hmare "map<char, 
                //vector<int>m" me koi eska character h jiski frequency count of indexes is exactly
                // one "indexesMap[curr_char].size()" es se kisi bhi character ka vector 
                //(jisme feq store h) uska size pata chal jayega
                //"indexesMap[curr_char].size() - j" like hmara jo j hoga voh hamesha even hi hoga
                // toh agar size of vector - j exactly one hua toh matlab ki hmare pass exact ek 
                //char esa h jiski freq count of indexes of that character is odd toh usko bilkul 
                //center m dal dege uska last character
                ans[(s.length())/2] = indexesMap[curr_char][j];
                continue;
            }    
            ans[start] = indexesMap[curr_char][j];
            // indexesMap[curr_char][j] es line  kya ho raha h ki jase i=0 per curr_char m 'a' h fir
            // jo ye j wala loop h utni bar chalega jitni frequency hogi us charcter ke indexes ki
            // or j+=2 es liye kar rakha ki jitne bhi char hoge unko pair m print karge
            //ab jo hmara ans wala array h uske start m hmnae character ka index dal diya 
            //'indexMap[a][0]' j = 0 h abhi eska matlab ye h ki jo hmara map of char and vector h 
            //usmse jo 'a' char wale ka jo vector h uska '0rth' element matlab ki 'a' ka phela index
            //ans[start] m dal do
            ans[end] = indexesMap[curr_char][j+1]; 
            // esme kya kara h ki ko char 'a' ka dusra index h voh ans wale array m last se dal do 
            //jisse string palandromic ban jaye
            start++;
            end--;
        }        
    }
    for (int i = 0; i < s.length(); i++){
            cout << ans[i]+1 <<" ";
        }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        PrintPalindromeString(s);
        cout << endl;
    }
    return 0;
}