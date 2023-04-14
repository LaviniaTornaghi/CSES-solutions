#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<unordered_map<int, int>> adj;
vector<bool> visited;
vector<int> prv;

void dfs(int nd, int p=-1)
{
	visited[nd] = 1;
	prv[nd] = p;
	
	if(nd == N)
		return;
	
	for(auto u : adj[nd])
	{
		if(!visited[u.first] && u.second>0)
			dfs(u.first, nd);
	}	
}

void lugly(int nd)
{
	visited[nd] = 1;
	
	for(auto u : adj[nd])
	{
		if(!visited[u.first] && u.second>0)
			dfs(u.first, nd);
	}
}

int main()
{
	cin>>N>>M;
	adj.resize(N+1); visited.resize(N+1); prv.resize(N+1);
	
	while(M--)
	{
		int a, b;
		cin>>a>>b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	
	int flow = 0;
	
	while(666)
	{
		fill(visited.begin(), visited.end(), 0); 
		fill(prv.begin(), prv.end(), -1);
		
		dfs(1);
		
		if(prv[N]==-1)
			break;
			
		flow += 1;
		int nd = N;
		while(nd != 1)
		{
			adj[prv[nd]][nd] = 0;
			adj[nd][prv[nd]] = 1;
			nd = prv[nd];
		}
	}
	cout<<flow<<endl;
	
	fill(visited.begin(), visited.end(), 0);
	lugly(1);
	
	for(int i=1; i<=N; i++)
	{
		if(visited[i]) continue;
		
		for(auto u : adj[i])
			if(visited[u.first])
				cout<<u.first<<" "<<i<<endl;
	}
}
