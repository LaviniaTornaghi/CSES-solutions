#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, q;
vector<ll> v;

struct FenTree
{
	vector<ll> tree;
	
	void add(int i, int v)
	{
		for(++i; i<=n; i += i & (-i))
			tree[i] += v;
	}
	
	void add(int l , int r, int v)
	{
		add(l, v);
		add(r+1, -v);
	}
	
	ll query(int i)
	{
		ll res = 0;
		
		for(++i; i>0; i -= i & (-i))
			res += tree[i];
		return res;
	}
};

FenTree ft;

int main()
{
	cin>>n>>q;
	
	v.resize(n);
	ft.tree.resize(n+1);
	
	for(int i=0; i<n; i++)
	{
		cin>>v[i];
		ft.add(i, i, v[i]);
	}
	
	while(q--)
	{
		int type; cin>>type;
		
		if(type == 1)
		{
			int val, a, b;
			
			cin>>a>>b>>val;
			
			ft.add(a-1, b-1, val);
		}
		else
		{
			int p;
			cin>>p;
			
			cout<<ft.query(p-1)<<endl;
		}
	}
}
