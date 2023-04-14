#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#define ll long long

struct Query
{
	char c; int a, b;
};

int n, q, N, tmp=1; //N elementi nel segment tmp potenza di due superiore
vector<int>v;
vector<int> mem;
vector<Query>query;

struct SegTree
{
	vector<ll> tree;
	
	void init()
	{
		tree.resize(2*tmp);
	}
	
	void build(int i, int l, int r)
	{
		if(l==r)
			return;

		int mid = (l+r)/2;
		
		build(i*2, l, mid);
		build(i*2+1, mid+1, r);
		
		tree[i] = tree[i*2] + tree[i*2+1];
	}
	
	void update(int pos, ll value) // pos gia indicizzata da + tmp
	{
		tree[pos] += value;
		pos/=2;
		
		while(pos>0)
		{
			tree[pos] = tree[pos*2]+tree[pos*2+1];
			pos/=2;
		}
	}
	
	int sq, eq;
	
	ll query(int i, int l, int r)
	{
		if(l>eq || r<sq)
			return 0;
		
		if(l>=sq && r<=eq) 
			return tree[i];
			
		int mid = (l+r)/2;
		
		return query(i*2, l, mid) + query(i*2+1, mid+1, r);
	}

	void print()
	{
		for(int i=0; i<tmp*2; i++) cout<<tree[i]<<" ";
		cout<<endl;
	}
};


SegTree st;

int main()
{
	cin>>n>>q;
	v.resize(n);
	mem.resize(n);
	
	for(int i=0; i<n; i++)
	{
		cin>>v[i];
		mem[i] = v[i];
	}
	
	query.resize(q);
	
	for(int i=0; i<q; i++)
	{
		cin>>query[i].c>>query[i].a>>query[i].b;
		
		if(query[i].c == '!')
			mem.push_back(query[i].a);
		mem.push_back(query[i].b);
	}
	
	sort(mem.begin(), mem.end());
	mem.resize(unique(mem.begin(), mem.end()) - mem.begin());
	
	for(int i=0; i<n; i++)
	{
		v[i] = lower_bound(mem.begin(), mem.end(), v[i]) - mem.begin();
	}
	
	for(auto& [c, a, b]:query)
	{
		if(c=='?') //sostituisci
			a = lower_bound(mem.begin(), mem.end(), a) - mem.begin();
		b = lower_bound(mem.begin(), mem.end(), b) - mem.begin();
			
	}
	
	N = mem.size();
	while(tmp<N) tmp*=2;
	st.tree.resize(tmp*2);
	
	for(int i=0; i<n; i++) st.tree[tmp + v[i]]++;
	st.build(1, 0, tmp-1);
	
	for(auto [c, a, b] : query)
	{
		if(c=='!') //update
		{
			st.update(b+tmp, 1);
			st.update(v[a-1]+tmp, -1);
			v[a-1] = b;
			
			//st.print();
		}
		else
		{
			st.sq = a; st.eq=b;
			cout<<st.query(1, 0, tmp-1)<<endl;
		}
	}
}
