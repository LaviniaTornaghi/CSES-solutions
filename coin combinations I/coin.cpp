#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int n, x;
vector <int> v, dp;

int main()
{
	cin>>n>>x;
	v.resize(n); dp.resize(x+1);
	
	for(int i=0; i<n; i++)
	{
		cin>>v[i];
		
		if(v[i]<=x) dp[v[i]] = 1;
	}
	sort(v.begin(), v.end());
	
	for(int i=0; i<=x; i++)
	{
		vector<bool> marca(x+1, 0);
		for(int j=0; j<n; j++)
		{
			if(i-v[j] < 0) break;
			if(marca[v[j]]) continue;
			marca[i-v[j]] = 1;
			dp[i] += (dp[i-v[j]] % MOD);
			dp[i] %= MOD;
		}
	}
	
	for(auto it : dp) cout<<it<<" ";
	
	cout<<dp[x];
}
