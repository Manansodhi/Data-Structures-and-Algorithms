/*
Count Ways To Reach The N-th Stairs

Problem Statement
You have been given a number of stairs. Initially, you are at the 0th stair, and you need 
to reach the Nth stair. Each time you can either climb one step or two steps. You are 
supposed to return the number of distinct ways in which you can climb from the 0th step 
to Nth step.
Example :
N=3
We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or we can climb the first 
two-step and then one step i.e. {(0,2),(1, 3)} or we can climb first one step and then 
two step i.e. {(0,1), (1,3)}.

Input format :
The first line contains an integer 'T', which denotes the number of test cases or queries 
to be run. Then the test cases follow.
The first and the only argument of each test case contains an integer 'N', representing 
the number of stairs.
Output Format :
For each test case/query, print the number of distinct ways to reach the top of stairs. 
Since the number can be huge, so return output modulo 10^9+7.


Output for every test case will be printed in a separate line.
Note :
You do not need to print anything. It has already been taken care of.

Constraints :
1 <= T <= 100
0 <= N <= 10^18  {{{{{{{{  V.V.V.V.V IMPORTANT }}}}}}}} cannot not be done with 
memoization tabulation need time and space less than O(N) ==> O(Log N) can be done
with matrix exponenetation

Where 'T' is the number of test cases, and 'N' is the number of stairs.
Sample Input 1 :
2
2
3
Sample Output 1 :
2
3
Explanation Of Sample Input 1 :
In the first test case, there are only two ways to climb the stairs, i.e. {1,1} and {2}.

In the second test case, there are three ways to climb the stairs i.e. {1,1,1} , {1,2} 
and {2,1}.
Sample Input 2 :
2
4
5
Sample Output 2 :
5
8
Explanation Of Sample Input 2 :
In the first test case, there are five ways to climb the stairs i.e. {1,1,1,1} , {1,1,2} ,
 {2,1,1} , {1,2,1} , {2,2}.

In the second test case, there are eight ways to climb the stairs i.e. {1,1,1,1,1} , 
{1,1,1,2} , {1,1,2,1}, {1,2,1,1}, {2,1,1},{2,2,1},{2,1,2} and {2,2,1}.
*/


//Brute Force
/*
    Time Complexity : O(2^N)
	There will be ‘N’ steps to climb, and at every step, we have two options to climb. So 
	there will be 2^N ways to climb ‘N’ stairs which is the size of the recursion tree.

    Space Complexity : O(N)
    In the worst-case scenario, when we climb one step each time, then the depth of the 
    recursion tree will be ‘N’. Where ‘N’ is the number of stairs.
*/

#define MOD 1000000007
int RecursiveCall(long long currStep, long long nStairs){
	//  Base Case: Invalid steps
	if(currStep>nStairs){
		return 0;
	}

	  //  We reached our destination return that we got one way to reach nStairs
	if(currStep=nStairs){
		return 1;
	}
	int oneStepcount = RecursiveCall(currStep+1, nStairs);//  Climb one stairs
	int twoStepcount=RecursiveCall(currStep+2, nStairs);//  Climb two stairs
	return (oneStepcount+twoStepcount)%MOD;
}


int countDistinctWayToClimbStair(long long nStairs){
	int totalWay= RecursiveCall(0,nStairs);
	return totalWay;
}



//Using Memoization
/*
In the previous approach, we were naively calculating the results for every step. So 
there were lots of redundant calls because if we look at the recursion tree, then there
are only ‘N’ distinct function calls. So we should avoid redundant function calling. 
For that, we decide to store the result at each step, and we will directly return the
result for that step whenever a function is called again for those steps. We will be
storing the result into “dp”.

Where dp[currStep] defines the number of distinct ways to climb the stairs from “currStep” 
to ‘N’-th steps.


Note : 
Since N can be 10^18 so even if you will be creating the array of integers then also 
it'll give the memory limit to exceed.


Time Complexity == O(N), Where ‘N’ is the number of stairs.
Since there will be only ‘N’ distinct function calls because we are saving the result 
at every step so there will be no redundant function calls, so overall time complexity 
will be O(N).

Space Complexity == O(N)+O(N)-->O(N) , Where ‘N’ is the number of stairs.
We are storing the result of every step in the dp array of size N. So there will be ‘N’ 
steps, And also we are using recursion to explore all the possible steps. So in the 
worst-case scenario, when we climb one step each time, then the depth of the recursion 
tree will be ‘N’. So space complexity will be O(N).
*/


#define MOD 1000000007
int RecursiveCall(long long currStep, vector<long long>& dp, long long nStairs){
	//  Base Case: Invalid steps
    if (currStep > nStairs)
    {
        return 0;
    }

    //  Check we have already solution or not?
    if(dp[nStairs] != -1){
    	return dp[nStairs];
    }

    //  We reached our destination return that we got one way to reach nStairs
    if (currStep == nStairs)
    {
        return 1;
    }
    //  Climb one stairs
    int oneStepcount = RecursiveCall(currStep + 1, dp, nStairs);

    //  Climb two stairs
    int twoStepCount = RecursiveCall(currStep + 2, dp, nStairs);

    int totalCount = (oneStepcount + twoStepCount) % MOD;

    //  Store for later use
    dp[currStep] = totalCount;

    return totalCount;

}


int countDistinctWayToClimbStair(long long nStairs){
	vector<long long>dp(nStairs+1, -1);
	int totalWay= RecursiveCall(0,dp,nStairs);
	return totalWay;
}


//Using Dynamic Programming

/*
As we have seen that this problem can be broken into subproblems. And many subproblems 
were the same, so for that; we were using memoization. So instead of storing the result 
through recursion, we are going to store the result iteratively. Our intuition is:

QUES-How can we reach “currStep” step in taking one step or two steps:
ANSWER --> 
1.We can take the one-step from (currStep-1)th step or,
2.We can take the two steps from (currStep-2)th step.
So the total number of ways to reach “currStep” will be the sum of the total number of 
ways to reach at (currStep-1)th and the total number of ways to reach (currStep-2)th step.

*/

/*
    Time Complexity : O(N)  
    We are traversing in “dp” only once to fill the”dp”  TIME LIMIT EXCEED (10^18)
    Space Complexity : O(N)  
    Since we are storing the result into “dp” for every step, there will be ‘N’ steps.
    MEMORY LIMIT EXCEED (10^18)
    Where ‘N’ is the number of stairs.
*/

#include <vector>
#define MOD 1000000007

int countDistinctWayToClimbStair(long long nStairs)
{
    vector<long long> dp(nStairs + 1);

    //  For single stair only
    dp[0] = 1;

    //  For two stairs
    dp[1] = 1;

    //  Go all stairs
    for (int currStep = 2; currStep <= nStairs; currStep++)
    {
        //  Get the number of way to reach currStep
        dp[currStep] = (dp[currStep - 1] + dp[currStep - 2]) % MOD;
    }

    return dp[nStairs];
}


//Matrix Multiplication / Matrix Exponentiation

/*
In the previous approach, we were using “dp” which took O(N) space. But there was no need 
of taking a space of O(N). Because if we look at any step of dp: 
dp[ currStep ] = dp[ currStep-1 ] + dp[ currStep-2 ]

We only need the answer of the two-step and the one-step before the “currStep” for evaluation 
of the “currStep”. So we can replace “dp” with two variables let’s say “oneStep” and “twoSteps”. 
Where “oneStep” denotes the total number of ways to reach (currStep-1)th step from beginning and
“twoSteps” denotes the total number of ways to reach (currStep-2)th step from the beginning. So,
currStep = oneStep + twoStep
So the above statement is (N-1)th Fibonacci Number. We can calculate the ‘N’th Fibonacci Number 
using Binary Matrix Exponentiation explained below. Here, Fn represents the nth Fibonacci number. 
We will raise the matrix to the power of (n - 1) so that the top-left element gives the value of 
F(n + 1 - 1) = F(n). 

[[1 1] (pow n)          [ [(F(n+1)  F(n)]
[1 0]]           =        [F(n)      F(n-1)] ]

 
So we need to find the (N - 1)th Power of this Matrix.
We can write a function for the multiplication of two matrices.
Then we can use binary exponentiation to calculate the ‘N’ power of this Matrix in log(N).
Binary Exponentiation / Fast Exponentiation:

long long binpow(Matrix a, long long b) {
if (b == 0)
     return 1;
Matrix res = binpow(a, b / 2);
if (b % 2)
     return res * res * a;
else
     return res * res;
}

Similarly, we can write a version for Matrix Exponentiation.
Take care of overflow using modulo by 10^9 + 7 at each operation of Matrix Multiplication.

Time Complexity  O(log(N)), where N is the number of stairs.
As we are diving N by 2 till it becomes 0, so that’s log(N) times multiplication of 2*2 Matrix. 
So Overall Time Complexity is O(log(N)).

Space Complexity  O(log(N)), 
Recursion stack takes O(log N) space. So Overall space complexity is O(log N).

*/

#define MOD 1000000007

void multiply(long long F[2][2], long long M[2][2])
{
    /*
        Logic for Multiplication of Matrix 'F' and Matrix 'M' 
    */

    long long x = (F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD;
    long long y = (F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD;
    long long z = (F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD;
    long long w = (F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD;

    F[0][0] = x % MOD;
    F[0][1] = y % MOD;
    F[1][0] = z % MOD;
    F[1][1] = w % MOD;

    //OR
    vector<vector<long long>> ans(1,vector<long long>(2,0));
    for(int i=0;i<2;i++){
    	for(int j=0;j<2;j++){
    		for(int k=0;k<2;k++){
    			ans[i][j] += mat1[i][k] * mat2[k][j] % MOD;
    		}
    	}
    }
    return ans;
}


void power(long long a[2][2], long long nStairs)
{
    /*
        Binary Matrix Exponentiation
    */

    if (nStairs == 0 || nStairs == 1)
    {
        return;
    }

    long long M[2][2] = {{1, 1}, {1, 0}};

    power(a, nStairs / 2);

    multiply(a, a);

    if (nStairs % 2 == 1)
    {
        multiply(a, M);
    }
}


int fib(long long nStairs)
{
    long long a[2][2] = {{1, 1}, {1, 0}};

    if (nStairs == 0)
    {
        return 0;
    }

    power(a, nStairs - 1);

    return a[0][0];
}


int countDistinctWayToClimbStair(long long nStairs)
{
    //  The no. of ways to climb the nStairs is (nStairs+1)th Fibonacci Number
    return fib(nStairs + 1);
}
