#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int N, Q;
	cin>>N>>Q;
	vector<int>v(N), ps(N+1);
	for(int i=0; i<N; i++)
		cin>>v[i];
		
	for(int i=1; i<=N; i++)
		ps[i] = ps[i-1] + v[i-1];
		
	while(Q--)
	{
		int a, b; cin>>a>>b;
		a--; b--;
		cout<<ps[b+1]-ps[a]<<endl;
	}
}
