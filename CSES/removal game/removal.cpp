#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> dp;
vector<ll> ps, v; //prefix sum + coso corrente
int n;

int main()
{
	cin>>n;
	v.resize(n);
	ps.resize(n);
	dp.resize(n, vector<ll>(n));
	
	for(int i=0; i<n; i++)
	{
		cin>>v[i];
		if(i>0)
			ps[i] = ps[i-1] + v[i];
		else 
			ps[i] = v[i];
	}
	
	for(int i=0; i<n; i++) dp[i][i] = v[i];
	
	for(int p=1; p<n; p++) //colonna di partenza della diagonale
	{
		int i=0, j=p; //i riga, j colonna
		
		for(;i<n && j<n; i++, j++)
		{
			ll sum;
			if(i==0) sum = ps[j];
			else sum = ps[j]-ps[i-1];
			
			ll opt = min(dp[i][j-1], dp[i+1][j]);
			
			dp[i][j] = sum -opt;
		}
	}
	cout<<dp[0][n-1];
}
