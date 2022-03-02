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
	dp[2] = 3 ; 
	dp[3] = 5 ; 
	for(int idx = 4 ; idx <= in ; idx++)
	{
		dp[idx] = (dp[idx - 1] + dp[idx - 2] * 2) % 10007 ; 
	}
	cout << dp[in] ;
	return 0 ; 
}

/* MEMO

*/
