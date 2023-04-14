#include <bits/stdc++.h>
using namespace std;
#define s 0
#define t 2*N+1

int N;
vector<map<int, bool>> gr; //0 sorgente 2*N+1 pozzo
vector<int> prv;
vector<bool> visited;

int main()
{
	cin>>N;
	gr.resize(t+1); prv.resize(t+1); visited.resize(t+1);

	for(int i=1; i<=N; i++)
	{
		for(int j=1+N; j<=2*N; j++)
		{
			char ch; cin>>ch;
			if(ch=='o')
				gr[i][j] = 1;
		}
	}

	for(int i=1; i<=N; i++) gr[0][i] = 1;
	for(int j = N+1; j<=2*N; j++) gr[j][t] = 1;
	
	int f=0;

	while(true)
	{
		fill(prv.begin(), prv.end(), -1);
		fill(visited.begin(), visited.end(), 0);

		stack<pair<int, int>> st;
		st.push({0, -1});

		while(!st.empty())
		{
			int nd = st.top().first, p = st.top().second;
			st.pop();

			visited[nd] = 1; prv[nd] = p;

			if(nd == t) break;

			for(auto [u,b] : gr[nd])
				if(b && !visited[u])
					st.push({u, nd});
		}

		if(!visited[t]) break;
		
		f++;

		int nd = t;

		while(nd)
		{
			gr[nd][prv[nd]] = 1;
			gr[prv[nd]][nd] = 0;
			nd = prv[nd];
		}
	}
	cout<<f<<endl;

	fill(visited.begin(), visited.end(), 0);
	
	vector<bool> in(t+1); // included in maxmatching
	
	for(int i= N+1; i<= 2*N; i++)
	{
		for(auto [u,b] : gr[i])
			if(b && u !=t)
			{
				in[i] = 1;
				in[u] = 1;
			}
	}
	
	for(int i=1; i<=N; i++)
	{
		if(!in[i])
		{
			stack<int> st; st.push(i);

			while(!st.empty())
			{
				int nd = st.top(); st.pop();
				visited[nd] = 1;
				for(auto [u, b] : gr[nd])
					if(b && !visited[u] && u!=0 && u!=t)
						st.push(u);
			}
		}
	}

	for(int i=1; i<= N; i++)
		if(!visited[i]) cout<<"1 "<<i<<endl;

	for(int i=N+1; i<t; i++)
		if(visited[i]) cout<<"2 "<<i-N<<endl;

}
