#include <iostream>
using namespace std ; 

const int SIZE = 1001 ; 
unsigned long long dp[SIZE] { } ; 

int main()
{
	cin.tie(nullptr) ; 
	cin.sync_with_stdio(false) ; 

	int in = 0 ;
	cin >> in ; 
	dp[1] = 1 ; 
	dp[2] = 2 ; 
	dp[3] = 3 ; 
	for(int idx = 4 ; idx <= in ; idx++)
	{
		dp[idx] = (dp[idx - 1] + dp[idx - 2]) % 10007 ; 
	}
	cout << dp[in] ;
	return 0 ; 
}

/* MEMO
	1 : 1 
	2 : 2
	3 : 3 
	4 : 5 
	5 : 8 
	6 : 13
	7 : 21
	8 : 34
	9 : 55
*/
