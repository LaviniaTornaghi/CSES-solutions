#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
 
vector<vector<ll>> dp;
int n;
ll targetsum;

ll fastexp(int b, int exp)
{
	if(exp == 0) return 1;
	if(exp == 1) return b;
	
	ll res = fastexp(b, exp/2) %MOD;
	
	res = (res * res) % MOD;
	if(exp%2==1)
	{
		res *= b;
		res %=MOD;
	}
	return res;
}
 
int main()
{
	cin>>n;
	
	if((n*(n+1)) %4 != 0)
	{
		cout<<0;
		return 0;
	}
	
	targetsum = n*(n+1) / 4;
	
	dp.resize(targetsum+1, vector<ll>(n+1));
	
	for(int i=0; i<=n; i++) dp[0][i] = 1;
	
	for(int i=1; i<=n; i++)
	{
		for(int j= 1; j<=targetsum; j++)
		{
			//se la somma è piu piccola del numero il numero non puo contribuire
			if(j-i < 0)
			{
				dp[j][i] = dp[j][i-1];
				dp[j][i] %= MOD;
				continue;
			}
			
			dp[j][i] = (dp[j][i-1] + dp[j-i][i-1])%MOD;
			dp[j][i] %= MOD;
		}
	}
	cout<<(dp[targetsum][n] * fastexp(2, MOD-2))%MOD;
}
