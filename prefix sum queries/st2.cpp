#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> ps, v;
int n, tmp=1, q;

struct SegTree
{
	vector<ll>tree;
	vector<ll>lazy;
	int sq, eq, value;
	
	void init()
	{
		tree.resize(2*tmp);
		lazy.resize(2*tmp);
		
		build(1, 0, tmp-1);
	}
	
	void build(int i, int l, int r)
	{
		if(l==r)
		{
			tree[i] = ps[i-tmp];
			return;
		}
		
		int mid = (l+r)/2;
		build(i*2, l, mid);
		build(i*2+1, mid+1, r);
		tree[i] = max(tree[i*2], tree[i*2+1]);
	}
	
	void update(int pos, int v)
	{
		value = v; sq = pos; eq = n -1;
		update(1, 0, tmp-1);
	}
	
	void update(int i, int l, int r)
	{
		if(lazy[i]!=0)
		{
			tree[i] += lazy[i];
			if(l!=r)
			{
				lazy[i*2] += lazy[i];
				lazy[i*2+1] += lazy[i];
			}
			lazy[i] = 0;
		}
		
		if(l>eq || r<sq)
			return;
			
		if(l>=sq && r<=eq)
		{
			tree[i]+=value;
			if(l!=r)
			{
				lazy[i*2] += value;
				lazy[i*2+1] += value;
			}
			return;
		}
		int mid=(l+r)/2;
		update(i*2, l, mid);
		update(i*2+1, mid+1, r);
		tree[i] = max(tree[i*2], tree[i*2+1]);
	}
	
	ll query(int a, int b)
	{
		sq = a; eq = b;
		return query(1, 0, tmp-1);
	}
	
	ll query(int i, int l, int r)
	{
		if(lazy[i]!=0)
		{
			tree[i] += lazy[i];
			if(l!=r)
			{
				lazy[i*2] += lazy[i];
				lazy[i*2+1] += lazy[i];
			}
			lazy[i] = 0;
		}
		
		if(l>eq || r<sq)
			return LLONG_MIN;
			
		if(l>=sq && r<=eq)
			return tree[i];
			
		int mid = (l+r)/2;
		
		return max(query(i*2, l, mid), query(i*2+1, mid+1, r));
	}
	
	void print()
	{
		cout<<"\n tree\n";
		for(int i=0; i<2*tmp; i++) cout<<tree[i]<<" ";
		cout<<"\nlazy\n";
		for(int i=0; i<2*tmp; i++) cout<<lazy[i]<<" ";
		cout<<endl;
	}
};

SegTree st;

int main()
{
	cin>>n>>q;
	n++; //mettiamo lo 0 per le somme prefisse
	while(tmp<n) tmp*=2;
	
	ps.resize(tmp); v.resize(tmp);
	
	for(int i=1; i<n; i++)
	{
		cin>>v[i];
		ps[i] = ps[i-1] + v[i];
	}
	
	st.init();

	while(q--)
	{
		int type; cin>>type;
		if(type==1) // update
		{
			int pos, value; cin>>pos>>value;
			
			st.update(pos, value-v[pos]);
			v[pos] = value;
		}
		else //query
		{
			int a, b; cin>>a>>b;
			
			cout<<max((ll)0, st.query(a, b) - st.query(a-1, a-1))<<endl;
		}
	}
}
