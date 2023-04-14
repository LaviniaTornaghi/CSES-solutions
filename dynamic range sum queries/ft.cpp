#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, q;
vector<ll> v;

struct FenTree
{
	vector<ll> tree;
	
	void init()
	{
		tree.resize(n+2);
	}
	
	ll sum(int r)
	{
		ll res=0;
		
		for(++r; r>0; r-= r & -r)
			res += tree[r];
			
		return res;
	}
	
	ll query(int l, int r)
	{
		return sum(r) - sum(l-1);
	}
	
	void update(int p, int v)
	{
		for(++p; p<n+1; p += p & -p)
			tree[p] += v;
	}
};

FenTree ft;

int main()
{
	cin>>n>>q;
	ft.init();
	v.resize(n+1);
	for(int i=1; i<=n; i++)
	{
		cin>>v[i];
		ft.update(i, v[i]);
	}

	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int pos, value;
			cin>>pos>>value;
			
			ft.update(pos, value - v[pos]);
			v[pos] = value;
		}
		else
		{
			int a, b;
			cin>>a>>b;
			
			cout<<ft.query(a, b)<<endl; //inclusi inclusi
		}
	}
}
