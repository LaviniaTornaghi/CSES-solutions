#include <bits/stdc++.h>
using namespace std;

vector<int> dsu;
int N, M;


int find(int a)
{
	if (dsu[a]==a) return a;
	
	return dsu[a] = find(dsu[a]);
}

void unite(int a, int b)
{
	a = find(a); b=find(b);
	if(b!=a)
		dsu[b] = a;
}

vector<pair<int,int>> res;

int main()
{
	cin>>N>>M;
	
	dsu.resize(N+1);
	
	iota(dsu.begin(), dsu.end(), 0);
	
	
	while(M--)
	{
		int a, b;
		cin>>a>>b;
		unite(a, b);
	}
	
	//for(int i=1; i<=N; i++) cout<<i<<" "<<find(i)<<endl;
	//return 0;
	
	for(int i=2; i<=N; i++)
	{
		find(i);
		
		//cout<<i<<" "<<dsu[i]<<endl;
		
		if(dsu[i]!=find(i-1))
		{
			unite(i-1,i);
			res.push_back({i-1, i});
		}
		
	}
	find(1);
	if(dsu[1] != find(2))
		res.push_back({1, 2});
	cout<<res.size()<<endl;
	
	for(auto it:res)
		cout<<it.first<<" "<<it.second<<endl;
}
