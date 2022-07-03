/*
Matrix Chain Multiplication

Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these 
matrices. The cost of matrix multiplication is defined as the number of scalar multiplications. A Chain 
of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the 
dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.
For example:
For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]
Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.

Constraints:
1 <= T <= 5
2 <= N <= 100
1 <= arr[i] <= 400 
Time Limit: 1 sec.

Sample Input 1:
4
4 5 3 2
4
10 15 20 25

Sample Output 1:
8000
70

Sample Output Explanation 1:

In the first test case, there are three matrices of dimensions A = [4 5], B = [5 3] and C = [3 2]. The 
most efficient order of multiplication is A * ( B * C).
Cost of ( B * C ) = 5 * 3 * 2 = 30  and (B * C) = [5 2] and A * (B * C) = [ 4 5] * [5 2] = 4 * 5 0. * 2 = 4
So the overall cost is equal to 30 + 40 =70.

In the second test case, there are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then the number of multiplications required is 11250.
If we multiply in order- (A1*A2)*A3, then the number of multiplications required is 8000.
Thus a minimum number of multiplications required is 8000. 

Sample Input 2:
4
1 4 3 2

Sample Output 2:
18

Explanation of Sample Output 2:
In the first test case, there are three matrices of dimensions A = [1 4], B = [4 3] and C = [3 2]. 
The most efficient order of multiplication is (A *  B) * C .
*/

//RECURSIVE
int f(int i, int j, vector<int> &arr){
    //base case
    if(i==j)
        return 0;
    
    //do partitions
    int mini=1e9;
    for(int k=i;k<=j-1;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + f(i,k,arr) + f(k+1,j,arr);
        
        mini = min(mini,steps);
    }
    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    return f(1,N-1,arr);
}

//MEMOIZATION
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    //base case
    if(i==j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    //do partitions
    int mini=1e9;
    for(int k=i;k<=j-1;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
        
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N,-1));
    return f(1,N-1,arr,dp);
}

//TABULATION


int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N,0));
    
    //base case
    for(int i=1;i<N;i++){
        dp[i][i] = 0;
    }
    
    for(int i=N-1; i>=1;i--){
        for(int j=i+1;j<=N-1;j++){
            //do partitions
            int mini=1e9;
            for(int k=i;k<=j-1;k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];

                mini = min(mini,steps);
            }
             dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}