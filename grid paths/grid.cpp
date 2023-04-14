#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int N;
vector<vector<int>> dp;

int rec(int r, int c)
{
	if(r>=N || c>=N) return 0;
	
	if(dp[r][c]!= -1) return dp[r][c];
	
	return dp[r][c] = ((rec(r+1,c)%MOD)+ (rec(r,c+1)%MOD)) % MOD;
}

int main()
{
	cin>>N;
	
	dp.resize(N, vector<int> (N, -1));
	dp[N-1][N-1] = 1;
	
	for(int i=0; i<N; i++)
	{
		char ch;
		for(int j=0; j<N; j++)
		{
			cin>>ch;
			if(ch == '*') dp[i][j] = 0;
		}
	}
	
	rec(0,0);
	cout<<dp[0][0];
}

