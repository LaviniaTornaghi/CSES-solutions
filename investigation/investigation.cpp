#include <bits/stdc++.h> 
using namespace std;
#define MOD 1000000007
#define ll long long

int N, M;

struct Arco
{
	int b;
	int p;
};

struct Nodo
{
	vector<Arco> ar;
	ll mr; //minimum routs
	ll minr, maxr; //min number of routes maximum number of routes
};

struct Dist
{
	int nxtnd;
	int prev;
	ll dist;
	ll visited;
	
	bool operator <(const Dist & other)const
	{
		if(dist==other.dist)
			return nxtnd>other.nxtnd;
		return dist>other.dist;
	}
};

vector<Nodo> gr;
ll marca[100005]; //ci salvo la dist minima per arrivare al nodo

int main()
{
	cin>>N>>M;
	gr.resize(N);
	
	for(int i=0; i<100005; i++) marca[i] = -1;
	for(int i=0; i<M; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		a--; b--;
		gr[a].ar.push_back({b,c});
	}
	
	priority_queue <Dist> pq;
	pq.push({0,0,0,0});
	gr[0].mr=1;
	
	while(!pq.empty())
	{
		int nd = pq.top().nxtnd;
		ll dist = pq.top().dist;
		ll visit = pq.top().visited;
		int prev = pq.top().prev;
		pq.pop();
		
		if(marca[nd]!=-1)
			continue;
		
		marca[nd] = dist;
		gr[nd].mr = gr[prev].mr;
		gr[nd].minr = gr[prev].minr+1;
		gr[nd].maxr =gr[prev].maxr+1;
		
		while(!pq.empty() && pq.top().nxtnd==nd && pq.top().dist == dist)
		{	
			gr[nd].mr+= gr[pq.top().prev].mr;
			gr[nd].mr %=MOD;
			gr[nd].minr = min(gr[nd].minr, gr[pq.top().prev].minr+1);
			gr[nd].maxr = max(gr[nd].maxr, gr[pq.top().prev].maxr+1);
			pq.pop();
		}
		
		for(auto figli : gr[nd].ar)
		{
			pq.push({figli.b, nd, dist+figli.p, visit +1});
		}
	}
	
	cout<<marca[N-1]<<" "<<gr[N-1].mr<<" "<<gr[N-1].minr-1<<" "<<gr[N-1].maxr-1<<endl;
}
