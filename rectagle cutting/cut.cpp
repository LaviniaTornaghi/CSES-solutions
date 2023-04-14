#include <bits/stdc++.h>
using namespace std;

int a, b;
vector<vector<int>> dp;

void print()
{
	for(int i=0; i<=a; i++)
	{
		for(int j=0; j<=a; j++)
			cout<<dp[i][j]<<" ";;
			cout<<endl;
	}
}

int main()
{
	cin>>a>>b;
	if(b>a) swap(a,b);
	
	dp.resize(a+1, vector<int>(a+1, INT_MAX));
	
	dp[1][1] = 0;
	for(int i=1; i<=a; i++) dp[1][i] = i-1;
	for(int i=1; i<=a; i++) dp[i][1] = i-1;
	
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=a; j++)
		{
			if(j==i)
			{
				dp[i][j] = 0;
				continue;
			}
			for(int k=1; k<=(i/2); k++)
				dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
			
			for(int k=1; k<=(j/2); k++)
				dp[i][j] = min(dp[i][j], 1 + dp[i][k]+ dp[i][j-k]);
				
			dp[j][i] = dp[i][j];
		}
	}
	cout<<dp[a][b];
}
