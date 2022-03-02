#include <iostream>
using namespace std ; 

const int SIZE = 12 ; 
unsigned int dp[SIZE] { } ; 

int main()
{
	dp[1] = 1 ; 
	dp[2] = 2 ; 
	dp[3] = 4 ; 
	cin.tie(nullptr) ; 
	cin.sync_with_stdio(false) ;

	int t = 0 ; 
	int in = 0 ;
	cin >> t ; 

	for(int idx = 4 ; idx < SIZE ; idx++)
	{
		dp[idx] = dp[idx - 3] + dp[idx - 2] + dp[idx - 1] ; 
	}
	while(t--)
	{
		cin >> in ;
		cout << dp[in] << '\n' ;
	}
	return 0 ; 
}

/* MEMO
	3 
	1 1 1 
	2 1 
	1 2
	3 
*/
