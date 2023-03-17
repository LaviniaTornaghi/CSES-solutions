#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int n, w;
vector<int> pr, pg; //price pages

int main()
{
	cin>>n>>w;
	dp.resize(n, vector<int> (w+1));
	pr.resize(n); pg.resize(n);
	
	for(int i=0; i<n; i++) cin>>pr[i];
	for(int i=0; i<n; i++) cin>>pg[i];	
	
	for(int i=pr[0]; i<=w; i++) dp[0][i] = pg[0];
	
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<=w; j++)
		{
			if(j-pr[i] <0)
			{
				dp[i][j] = dp[i-1][j];
				continue;
			}
			if(dp[i-1][j]<pg[i]+dp[i-1][j-pr[i]]) //conviene prendere il secondo
				dp[i][j] = pg[i]+dp[i-1][j-pr[i]];
			else
				dp[i][j] = dp[i-1][j];
				
		}
	}
	cout<<dp[n-1][w];
}

