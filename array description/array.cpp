#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll n, m, res;
vector<ll> v;
vector<vector<ll>> dp;

int main()
{
	cin>>n>>m;
	v.resize(n+1);
	dp.resize(m+2, vector<ll> (n+1, 0));
	
	for(int i=1; i<=n; i++) cin>>v[i];
	
	//caso base
	if(v[1]==0)
		for(int i=1; i<=m; i++) dp[i][1] = 1;
	else
		dp[v[1]][1] = 1;
	
	for(int i=2;i<=n; i++)
	{
		if(v[i] != 0) //numero bloccato
		{
			dp[v[i]][i] = (dp[v[i]-1][i-1] + dp[v[i]][i-1] + dp[v[i]+1][i-1]) % MOD;
			dp[v[i]][i] %= MOD;
			continue;
		}
		
		for(int j=1; j<=m; j++)
		{
			dp[j][i] = (dp[j-1][i-1] + dp[j][i-1] + dp[j+1][i-1]) %MOD;
			dp[j][i] %=MOD;
		}
	}

	for(int i=1; i<=m; i++)
	{
		res += dp[i][n];
		res%=MOD;
	}
	cout<<res;
}
