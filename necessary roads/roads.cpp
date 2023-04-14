#include <bits/stdc++.h>
using namespace std;
#define db if(nd == 5)

vector<vector<int>> gr;
vector<int>visited;
vector<int> low, tin;
vector<pair<int, int>> roads;
int N, M, t=0;

void dfs(int nd, int p=-1)
{
	visited[nd] = 1;
	low[nd] = tin[nd] = t++;

	for(auto u : gr[nd])
	{
		if(u==p) continue;
		if(visited[u])
			low[nd] = min(low[nd], tin[u]);
		else
		{
			dfs(u, nd);
			if(low[u]>tin[nd])
			{
					roads.push_back({nd, u});
			}
			low[nd] = min(low[nd], low[u]);
		}
	}
}

int main()
{
	cin>>N>>M;
	gr.resize(N+1); visited.resize(N+1); low.resize(N+1); tin.resize(N+1);
	
	while(M--)
	{
		int a, b;
		cin>>a>>b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	
	dfs(1);
	
	cout<<roads.size()<<endl;
	
	for(auto it: roads) cout<<it.first<<" "<<it.second<<endl;
}
