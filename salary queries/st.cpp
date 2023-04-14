#include <bits/stdc++.h>
using namespace std;

int n, q, tmp=1, N; //N elementi nel segment
vector<int> v;

struct Query
{
	char type;
	int a, b;
};

vector<Query>query;
map<int, int> mp;
vector<int> marca;

struct SegTree
{
	vector<int> tree;
	int a, b;

	void update(int pos, int value) 
	{
		tree[pos] += value;
		pos/=2;
		
		while(pos>0)
		{
			tree[pos] = tree[pos*2]+tree[pos*2+1];
			pos/=2;
		}
	}
	
	void build(int i, int l, int r)
	{
		if(l==r)
			return;
		int mid = (l+r)/2;
		build(i*2, l, mid);
		build(i*2+1, mid+1, r);
		tree[i] = tree[i*2]+ tree[i*2+1];
	}
	
	int query(int i, int l, int r)
	{
		if(marca[l]> b || marca[r]<a)
			return 0;
			
		if(marca[l]>=a && marca[r]<=b)
		{
			return tree[i];
		}
			
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
	for(int i=0; i<n; i++)
	{
		cin>>v[i];
		mp[v[i]] = 1;
	}
	
	query.resize(q);
	for(int i=0; i<q; i++)
	{
		cin>>query[i].type>>query[i].a>>query[i].b;
		
		if(query[i].type == '!')
			mp[query[i].b] = 1;
	}
	
	N = mp.size();

	while(tmp<N) tmp*=2;
	
	marca.resize(tmp, INT_MAX);	
	
	int conta =0;
	for(auto it:mp) 
	{
		mp[it.first] = conta;
		marca[conta] = it.first;
		conta++;
	}
	
	st.tree.resize(2*tmp);
	
	for(int i=0; i<n; i++) st.tree[mp[v[i]]+tmp]++;
	
	st.build(1, 0, tmp-1);
	
	for(int i=0;i<q; i++)
	{
		char ch = query[i].type;

		if(ch == '!')
		{
			int pos = query[i].a, value = query[i].b;
			
			st.update(mp[value]+tmp, 1);
			st.update(mp[v[pos-1]]+tmp, -1);
			v[pos-1] = value;
		}
		else
		{
			st.a = query[i].a; st.b = query[i].b;
			
			cout<<st.query(1, 0, tmp-1)<<endl;
		}
	}
}
