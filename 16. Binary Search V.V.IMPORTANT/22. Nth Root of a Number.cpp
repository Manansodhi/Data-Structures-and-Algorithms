/*
Given two numbers N and M, find the Nth root of M.
The nth root of a number M is defined as a number X when raised to the power N equals M.

Example 1:
Input: N=3 M=27
Output: 3
Explanation: The cube root of 27 is 3.

Example 2:
Input: N=2 M=16
Output: 4
Explanation: The square root of 16 is 4

Example 3:
Input: N=5 M=243
Output: 3
Explaination: The 5th root of 243 is 3

Time Complexity: N x log(M x 10^d)
Space Complexity: O(1)
*/

class Solution {
public:
  double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}
    int mySqrt(int x) {
    double low = 1;
    double high = x;
    double eps = 1e-6; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, 2) < x) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
      return low;
    }
};

//Different type of question
//Square root up to P decimal places
float square_root(int N,int P){
    int s = 0;
    int e = N ;
    float ans = 0;

    //Binary Search (Search Space 0....N)
    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid==N){
            return mid;
        }
        else if(mid*mid < N){
            ans = mid;
            s = mid + 1;
        }

        else{
            e = mid - 1;
        }

    }

    //Linear Search for each place (for floating part)
    float inc = 0.1;

    fot placer(in=1;place<=P;place++){

        //do linear search
        while(ans*ans <=N){
            ans += inc;
        }

        //take one step back
        ans = ans - inc;
        inc = inc/10.0;
    }

   
    return ans;
}



int main(){

    int n,p;
    cin>>n>>p;

    cout<<square_root(n,p)<<endl;

    return 0;
}