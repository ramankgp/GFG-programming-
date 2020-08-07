//https://www.youtube.com/watch?v=0Q_U9_gryRg

// Approach: Firstly, let’s define a recursive solution to find the solution for nth element. 
//   There are two cases.
// The previous n – 1 elements are divided into k partitions, i.e S(n-1, k) ways. Put this nth element into one of the previous 
// k partitions. So, count = k * S(n-1, k)
// The previous n – 1 elements are divided into k – 1 partitions, i.e S(n-1, k-1) ways. Put the nth element into a new partition
// ( single element partition).So, count = S(n-1, k-1)
// Total count = k * S(n-1, k) + S(n-1, k-1).


// DP approach : Create a Dp array dp[n+1][k+1] of size ( n + 1 )* ( k + 1 ) .
// Fill the values of basic cases. For all values of i from 0 to n fill dp[i][0] = 0 and for all values of i from 0 to k fill dp[0][k] = 0
// Run a nested loop, the outer loop from 1 to n and inner loop from 1 to j.
// For index i and j (outer loop and inner loop respectively), calculate dp[i][j] = j * dp[i – 1][j] + dp[i – 1][j – 1] and if j == 1 or i == j, calculate dp[i][j] = 1.
// Print values dp[n][k]



// A Dynamic Programming based C++ program to count 
// number of partitions of a set with n elements 
// into k subsets 
#include<iostream> 
using namespace std; 

// Returns count of different partitions of n 
// elements in k subsets 
int countP(int n, int k) 
{ 
// Table to store results of subproblems 
int dp[n+1][k+1]; 

// Base cases 
for (int i = 0; i <= n; i++) 
	dp[i][0] = 0; 
for (int i = 0; i <= k; i++) 
	dp[0][k] = 0; 

// Fill rest of the entries in dp[][] 
// in bottom up manner 
for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= i; j++) 
	if (j == 1 || i == j) 
		dp[i][j] = 1; 
	else
		dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1]; 

return dp[n][k]; 
} 

// Driver program 
int main() 
{ 
cout << countP(5, 2); 
return 0; 
} 




