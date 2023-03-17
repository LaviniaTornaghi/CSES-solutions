#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int mem[1000005];

int dp(int n)
{
	if(mem[n]!=-1) return mem[n];
	if(n<=1) return 1;
	
	int res = 0;
	
	for(int i=1; i<=6 && n-i>=0; i++)
	{
		res += dp(n-i);
		res %= MOD;
	}
		
	mem[n] = res%MOD;
	return res%MOD;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<1000005; i++) mem[i] = -1;
	cout<<dp(n);
	
}

