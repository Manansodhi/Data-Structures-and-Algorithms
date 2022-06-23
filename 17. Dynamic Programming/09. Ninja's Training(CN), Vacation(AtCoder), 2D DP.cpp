/*
Ninja’s Training

Problem Statement
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these
three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some 
merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity 
in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and 
activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 
5 + 3 + 3.

Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.
The first line of each test case contains a single integer,' N’, denoting the number of days.
The next ‘N’ lines of each test case have 3 integers corresponding to POINTS[i].

Output Format:
For each test case, return an integer corresponding to the maximum coins  Ninja can collect.

Note:
You do not need to print anything. It has already been taken care of. Just implement the 
givenfunction.

Constraints:
1 <= T <= 10
1 <= N <= 100000.
1 <= values of POINTS arrays <= 100 .

Time limit: 1 sec

Sample Input 1:
2
3
1 2 5 
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90

Sample Output 1:
11
210

Explanation Of Sample Input 1:
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points. 
On the second day, Ninja will do running and earn 3 merit points. 
On the third day, Ninja will do fighting and earn 3 merit points. 
The total merit point is 11 which is the maximum. 
Hence, the answer is 11.

For the second test case:
One of the answers can be:
On the first day, Ninja will learn new moves and earn 70 merit points. 
On the second day, Ninja will do fighting and earn 50 merit points. 
On the third day, Ninja will learn new moves and earn 90 merit points. 
The total merit point is 210 which is the maximum. 
Hence, the answer is 210.

Sample Input 2:
2
3
18 11 19
4 13 7
1 8 13
2
10 50 1
5 100 11

Sample Output 2:
45
110
*/


//Recursion -- will give TLE

int f(int day, int LastActivity, vector<vector<int>>& points){
	//base case
	if(day==0) {
		int maxi=0;
		for(int Acitivity=0;Acitivity<=2;Acitivity++){
			if(Activity != LastActivity){
				maxi = max(maxi, points[0][Acitivity]);
			}
		}
		return maxi;
	}

	int maxi = 0;
	for(int Acitivity = 0; Acitivity<=2; Acitivity++){
		if(Acitivity!=LastActivity){
			int points = Acitivity[day][Acitivity] + f(day-1, Acitivity,points);
			maxi=max(maxi,points);
		}
	}
	return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){
	return f(n-1,3,points);
}


//Memoization

int f(int day, int LastActivity, vector<vector<int>>& points, vector<vector<int>> &dp){
	//base case
	if(day==0) {
		int maxi=0;
		for(int Acitivity=0;Acitivity<=2;Acitivity++){
			if(Activity != LastActivity){
				maxi = max(maxi, points[0][Acitivity]);
			}
		}
		return maxi;
	}

	if(dp[day][LastActivity] != -1){
		return dp[day][LastActivity];
	}

	int maxi = 0;
	for(int Acitivity = 0; Acitivity<=2; Acitivity++){
		if(Acitivity!=LastActivity){
			int point = points[day][Acitivity] + f(day-1, Acitivity,points,dp);
			maxi=max(maxi,point);
		}
	}
	return dp[day][LastActivity] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){
	vector<vector<int>> dp(n,vector<int>(4,-1));
	return f(n-1,3,points,dp);
}


//TABULATION
int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }

  }

  return dp[n - 1][3];
}



//SPACE Optimization
int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {

    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];
}
