#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
vector<vector<int>> adj;
int M, F, Q;
vector<int>prv;
vector<bool>visited;

void path(int nd, int p=-1)
{
	visited[nd] = 1;
	prv[nd] = p;
	
	if(nd == M+F+1)
		return;
		
	for(auto i : adj[nd])
	{
		if(!visited[i] && gr[nd][i]>0)
			path(i, nd);
	}
}

int main()
{
	cin>>M>>F>>Q;
	gr.resize(M+F+2, vector<int>(M+F+2)); visited.resize(M+F+2); prv.resize(M+F+2); adj.resize(M+F+2);
	while(Q--)
	{
		int a, b;
		cin>>a>>b;
		gr[a][b+M] = 1;
		adj[a].push_back(b+M);
		adj[b+M].push_back(a);
	}
	
	for(int i=1; i<=M; i++)
	{ 
		gr[0][i] = 1;
		adj[0].push_back(i);
	}
	for(int i=M+1; i<=M+F; i++)
	{
		gr[i][M+F+1]  =1;
		adj[i].push_back(M+F+1);
	}
	
	int flow = 0;
	
	while(true)
	{
		fill(visited.begin(), visited.end(), 0); fill(prv.begin(), prv.end(), -1);
		path(0);
		
		if(prv[M+F+1] == -1)
			break;
		
		flow += 1;
		int nd = M+F+1;
	
		while(nd!=0)
		{
			gr[prv[nd]][nd] = 0;
			gr[nd][prv[nd]] = 1;
			nd = prv[nd];
		}
	}
	
	cout<<flow<<endl;
	
	for(int i= M+1; i<=M+F; i++)
	{
		for(int j=1; j<=M; j++)
		{
			if(gr[i][j] == 1)
			{
				cout<<j<<" "<<i-M<<"\n";
			}
		}
	}
}
