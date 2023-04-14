#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


int n, x;
vector<int> v, dp;

int main()
{
	cin>>n>>x;
	v.resize(n); dp.resize(x+1);
	
	for(int i=0; i<n; i++) cin>>v[i];
	sort(v.begin(), v.end());
	
	dp[0] = 1;
	
	for(int i=0; i<n; i++)
	{
		for(int w = v[i]; w<= x; w++)
		{
			if(w-v[i]<0) break;
			
			dp[w] += dp[w-v[i]];
			dp[w] %=MOD;
		}
	}
	
	cout<<dp[x];
}
