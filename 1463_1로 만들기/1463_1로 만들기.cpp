#include <iostream>
#include <set>
using namespace std ; 

const int MAX_SIZE = 1000001 ; 
int main()
{
	cin.tie(nullptr) ; 
	cin.sync_with_stdio(false) ; 

	int *dp = new int[MAX_SIZE] ; 
	set<int> res ; 
	dp[1] = 0 ; 
	dp[2] = 1 ; 
	dp[3] = 1 ; 
	int in = 0 ; 
	cin >> in ; 
	for(int idx = 4 ; idx <= in ; idx++)
	{
		if(idx % 3 == 0)
		{
			res.insert(dp[idx / 3] + 1) ;
		}
		if(idx % 2 == 0)
		{
			res.insert(dp[idx / 2] + 1) ; 
		}
		if(idx % 1 == 0)
		{
			res.insert(dp[idx - 1] + 1) ; 
		}
		dp[idx] = *res.begin() ; 
		res.clear() ; 
	}
	cout << dp[in] ; 
	delete[] dp ; 
	return 0 ;
}

