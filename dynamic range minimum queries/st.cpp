#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n , q, tmp= 1;
vector<ll> v;

struct SegTree
{
	vector<ll> tree;
	
	void init()
	{
		tree.resize(2*tmp, LLONG_MAX);
		build(1, 0, tmp-1);
	}
	
	void build(int i, int l, int r)
	{
		if(l==r)
		{
			tree[i] = v[i-tmp];
			return;
		}
		int mid = (l+r)/2;
		
		build(i*2, l, mid);
		build(i*2+1, mid+1, r);

		tree[i] = min(tree[i*2] , tree[i*2+1]);
	}
	
	void update(int pos, ll value) // pos gia indicizzata da + tmp
	{
		tree[pos] = value;
		pos/=2;
		
		while(pos>0)
		{
			tree[pos] = min(tree[pos*2],tree[pos*2+1]);
			pos/=2;
		}
	}
	
	int sq, eq;
	
	ll query(int i, int l, int r)
	{
		if(l>eq || r<sq)
			return LLONG_MAX;
		
		if(l>=sq && r<=eq)
			return tree[i];
			
		int mid = (l+r)/2;
		
		return min(query(i*2, l, mid), query(i*2+1, mid+1, r));
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
	
	while(tmp<n) tmp*=2;
	
	v.resize(tmp, LLONG_MAX);
	for(int i=0; i<n; i++) cin>>v[i];
	
	st.init();

	while(q--) //ricorda pos--
	{
		int type; cin>>type;
		
		if(type == 1)
		{
			int p; ll v;
			cin>>p>>v;
			
			st.update(p+tmp-1, v);
		}
		else
		{
			int a, b;
			cin>>a>>b;
			st.sq = a-1; st.eq = b-1;
			
			cout<<st.query(1, 0, tmp-1)<<endl;
		}
	}
}

