#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
vector<int>visited;
vector<int> low, tin;
vector<int> points;
int N, M, t=0;

void dfs(int nd, int p=-1)
{
	visited[nd] = 1;
	low[nd] = tin[nd] = t++;
	int children = 0;
	bool printed = false;

	for(auto u : gr[nd])
	{
		if(u==p) continue;

		if(visited[u])
		{
			low[nd] = min(low[nd], tin[u]);
		}
		else
		{
			dfs(u, nd);
			if(low[u]>=tin[nd] && p!= -1)
			{
				if(!printed)
				{
					points.push_back(nd);
					printed = true;
				}
			}

			low[nd] = min(low[nd], low[u]);
			children ++;
		}
	}
	if(p==-1 && children >1)
		points.push_back(nd);
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
	
	cout<<points.size()<<endl;
	
	for(auto it: points) cout<<it<<" ";
}
