#include <bits/stdc++.h>
using namespace std;
#define db cout<<"quack";

int N, M;

vector<vector<int>> gr;
vector<int> team;
vector<bool> marca;

void visit(int i, int val)
{
	//cout<<i<<" "<<val<<endl;
	if(team[i]!=-1 && team[i]!= val)
	{
		cout<<"IMPOSSIBLE";
		exit(0);
	}
	if(marca[i]) return;
	
	marca[i] = true;
	team[i] = val;
	
	if(val==1) val = 2;
	else val = 1;
	
	for(auto it: gr[i])
		visit(it, val);
}

int main()
{
	cin>>N>>M;
	
	marca.resize(N+1);
	gr.resize(N+1);
	team.resize(N+1, -1);
	
	while(M--)
	{
		int a, b;
		cin>>a>>b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	for(int i=1; i<=N; i++)
	{
		if(!marca[i])
			visit(i, 1);
	}
	
	for(int i=1; i<=N; i++) cout<<team[i]<<" ";
}
