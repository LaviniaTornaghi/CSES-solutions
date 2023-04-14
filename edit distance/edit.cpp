#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
string a, b;

bool check(int i,int j)
{
	return !(a[i-1] == b[j-1]);
}

int main()
{
	cin>>a>>b;
	
	dp.resize(a.size() + 1, vector<int> (b.size() +1));
	
	for(int i=0; i<=b.size(); i++) dp[0][i] = i;
	for(int i=0; i<=a.size(); i++) dp[i][0] = i;
	
	for(int i=1; i<=a.size(); i++)
	{
		for(int j = 1; j<=b.size(); j++)
		{
			dp[i][j] = min({check(i, j) + dp[i-1][j-1], dp[i-1][j] +1, dp[i][j-1] + 1});
		}
	}
	cout<<dp[a.size()][b.size()];
}
