#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define BOUND 1000001

int t, n;
vector<ll> dp, f1, f2;

int main()
{
	cin>>t;
	dp.resize(BOUND); f1.resize(BOUND); f2.resize(BOUND);
	dp[1] = 2; f1[1] = 1; f2[1] = 1;
	
	for(int i=2; i< BOUND; i++)
	{
		ll res = (dp[i-1]*2) %MOD;
		res %=MOD;
		res += (f2[i-1]*3) %MOD;
		res %=MOD;
		res += (f1[i-1]) %MOD;
		res %=MOD;
		
		dp[i] = res;
		
		f2[i] = (dp[i-1] + f2[i-1]*3) % MOD;
		f1[i] = (dp[i-1] + f1[i-1]) % MOD;
	}
	
	while(t--)
	{
		cin>>n;
		cout<<dp[n]<<endl;
	}
}
