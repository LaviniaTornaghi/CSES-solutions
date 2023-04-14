#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;
vector<vector<bool>> marca;
int N,M;

void visit(int i, int j)
{
	if(i<0 || j<0 || i>=N || j>=M) return;
	if(v[i][j] == '#') return;
	if(marca[i][j]) return;
	marca[i][j] = true;
	
	visit(i+1, j);
	visit(i-1, j);
	visit(i, j-1);
	visit(i, j+1);
}

int main()
{
	cin>>N>>M;
	
	v.resize(N, vector<char> (M));
	marca.resize(N, vector<bool> (M));
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin>>v[i][j];
	
	int res = 0;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			if(v[i][j] == '#') continue;
			
			if(marca[i][j]) continue;
			
			res++;
			
			visit(i, j);
		}
	
	cout<<res;
}
