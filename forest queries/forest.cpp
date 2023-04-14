#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dp ps

vector<vector<ll>> ps;
int n, q;

void print()
{
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++) cout<<ps[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	cin>>n>>q;
	ps.resize(n+1, vector<ll> (n+1));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			char ch; cin>>ch;
			if(ch == '*') ps[i+1][j+1] = 1;
		}
	}	
	
	for(int i=1; i<=n; i++) ps[i][1] += ps[i-1][1];
	for(int j=1; j<=n; j++) ps[1][j] += ps[1][j-1];

	for(int i=2; i<=n; i++)
	{
		for(int j=2; j<=n; j++)
		{
			ps[i][j] += (ps[i-1][j]+ps[i][j-1] - ps[i-1][j-1]);
		}
	}

	while(q--)
	{
		int x1, x2, y1, y2;
		cin>>y1>>x1>>y2>>x2;
		
		cout<<dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1]<<endl;
	}
}
