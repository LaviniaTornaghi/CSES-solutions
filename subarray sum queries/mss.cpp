#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, tmp=1, q;
vector<ll>v;

struct Nodo
{
	ll sum;
	ll ps, ss, ms; //prefix sum //suffix sum //maximum sum
};

struct SegTree
{
	vector<Nodo> tree;
	int sq, eq;
	
	void init()
	{
		tree.resize(tmp*2);
		
		build(1, 0, tmp-1);
	}
	
	void build(int i, int l, int r)
	{
		if(l==r)
		{
			tree[i] = {v[i-tmp], max((ll)0,v[i-tmp]), max((ll)0,v[i-tmp]), max((ll)0,v[i-tmp])};
			return;
		}
		int mid = (l+r)/2;
		build(i*2, l, mid); build(i*2+1, mid+1, r);
		
		tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
		tree[i].ps = max(tree[i*2].ps, tree[i*2].sum + tree[i*2+1].ps);
		tree[i].ss = max(tree[i*2+1].ss, tree[i*2+1].sum + tree[i*2].ss);
		tree[i].ms = max({tree[i*2].ms, tree[i*2+1].ms, tree[i*2].ss + tree[i*2+1].ps});
	}
	
	void update(int pos, ll value) //gia +tmp -1
	{
		tree[pos] = {value, max((ll)0, value), max((ll)0, value), max((ll)0, value)};
		pos/=2;
		
		while(pos>0)
		{
			tree[pos].sum = tree[pos*2].sum + tree[pos*2+1].sum;
			tree[pos].ps = max(tree[pos*2].ps, tree[pos*2].sum + tree[pos*2+1].ps);
			tree[pos].ss = max(tree[pos*2+1].ss, tree[pos*2+1].sum + tree[pos*2].ss),
			tree[pos].ms = max({tree[pos*2].ms, tree[pos*2+1].ms, tree[pos*2].ss + tree[pos*2+1].ps});
			
			pos/=2;
		}
	}
	
	void print()
	{
		for(int i=0;i<2*tmp; i++) cout<<tree[i].sum<<" ";
		cout<<endl;
	}
};

SegTree st;

int main()
{
	cin>>n>>q;
	
	while(tmp<n) tmp*=2;
	
	v.resize(tmp);
	
	for(int i=0; i<n; i++) cin>>v[i];
	
	st.init();
	
	while(q--)
	{
		int p, v;
		cin>>p>>v;
		
		st.update(p+tmp-1, v);
		cout<<st.tree[1].ms<<endl;
	}
}
