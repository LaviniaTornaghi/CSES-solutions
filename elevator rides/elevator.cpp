#include <bits/stdc++.h>
using namespace std;

struct Info
{
	int r, w; //rides, weight of the last ride
};

int n, x;
vector<int> v;
vector<Info> dp;

Info minimum(Info &i1, Info &i2)
{	
	if(i1.r!=i2.r)
	{
		if(i1.r < i2.r) return i1;
		return i2;	
	}
	if(i1.w < i2.w) return i1;
		return i2;	
}

int main()
{
	cin>>n>>x;
	v.resize(n); dp.resize((1<<n));
	for(int i=0; i<n; i++) cin>>v[i];
	
	dp[0] = {1, 0};
	
	for(int i=1; i< (1<<n); i++)
	{
		//cout<<"\ninx "<<i<<endl;
		dp[i] = {n+1, 0};
		
		for(int j=0; j<n; j++)
		{
			if(i & (1<<j)) //se è presente nel subset
			{
			//	cout<<j<<" ";
				Info info = dp[i ^ (1<<j)];
				
				if(info.w + v[j] <= x)
				{
					info.w += v[j];
					dp[i] = minimum(dp[i], info);
				}
				else
				{
					info. r = info.r+1;
					info.w = v[j];
					dp[i] = minimum(dp[i], info);
				}
			}
		}
	}
	cout<<dp[(1<<n)-1].r;
}
