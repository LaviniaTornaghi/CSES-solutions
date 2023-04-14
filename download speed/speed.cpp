#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> gr;
vector<bool> visited;
vector<int> prv;
vector<int> mn;
int N, M;

void path(int nd, int p=-1)
{
	visited[nd] = 1;
	prv[nd] = p;
	
	if(nd == N)
		return;
	
	for(int i=1; i<=N; i++)
	{
		if(!visited[i] && gr[nd][i]>0)
		{
			mn[i] = min(mn[nd], gr[nd][i]);
			path(i, nd);
		}
	}
}

signed main()
{
	cin>>N>>M;
	gr.resize(N+1, vector<int> (N+1, 0)); visited.resize(N+1, 0); prv.resize(N+1, -1); mn.resize(N+1, INT_MAX);
	
	while(M--)
	{
		int a, b, p;
		cin>>a>>b>>p;
		gr[a][b] += p;
	}
	
	mn[1] = INT_MAX;
	
	int flow = 0;
	
	while(true)
	{
		path(1); 
		if(prv[N] == -1)
		{
			cout<<flow;
			break;
		}
		
		int delta = mn[N];
		int nd = N;
		
		while(nd!=1)
		{
			gr[prv[nd]][nd] -= delta;
			gr[nd][prv[nd]] += delta;
			nd = prv[nd];
		}
		flow += delta;
		fill(visited.begin(), visited.end(), 0);
		fill(prv.begin(), prv.end(), -1);
		fill(mn.begin(), mn.end(), INT_MAX);
	}
}
