#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v, original; 
int n, tmp=1, q;

struct SegTree
{
	vector<ll> tree;
	vector<ll> lazy;
	int value, sq, eq;
	
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
			tree[i] = v[i-tmp];
			return;
		}
		int mid =(l+r)/2;
		build(i*2, l, mid);
		build(i*2+1, mid+1, r);
		tree[i] = max(tree[i*2] ,tree[i*2+1]);
	}
	
	void update(int v, int s)
	{
		value = v; sq = s; eq = n-1;
		update(1, 0, tmp-1);
	}
	
	void update(int i, int l, int r)
	{
		//se ho un update lo propago
		if(lazy[i]!=0)
		{
			tree[i]+= (lazy[i]);
			if(l!=r)
			{
				lazy[i*2]+= lazy[i];
				lazy[i*2+1] += lazy[i];
			}
			lazy[i] = 0;
		}
		if(l>eq || r<sq)
			return;
			
		if(l>=sq && r<=eq) //se è totalmente incluso
		{
			tree[i] += (value);
			if(l!=r)
			 {
				lazy[i*2] += value;
				lazy[i*2+1] += value;
			}
			return; 
		}
		int mid = (l+r)/2;
		update(i*2, l, mid);
		update(i*2+1, mid+1, r);
		tree[i] = max(tree[i*2],tree[i*2+1]);
	}
	
	ll query(int s, int e)
	{
		sq = s; eq = e;
		return query(1, 0,  tmp-1);
	}
	
	ll query(int i, int l, int r)
	{
		if(lazy[i]!=0)
		{
			tree[i]+= (lazy[i]);
			if(l!=r)
			{
				lazy[i*2]+= lazy[i];
				lazy[i*2+1] += lazy[i];
			}
			lazy[i] = 0;
		}
		
		if(l>eq || r<sq)
			return LLONG_MIN;
			
		if(l>=sq && r<=eq) //se è totalmente incluso
		{
			return tree[i]; 
		}
		
		int mid = (l+r) /2;
		
		return max(query(i*2, l, mid), query(i*2+1, mid+1, r));
	}
	
	void print()
	{
		for(int i=0; i<2*tmp; i++) cout<<tree[i]<<" ";
		cout<<"\n lazy\n";
		for(int i=0; i<2*tmp; i++) cout<<lazy[i]<<" ";
		cout<<endl;
	}
};

SegTree st;

int main()
{
	cin>>n>>q;
	n++;
	while(tmp<n) tmp*=2;
	
	v.resize(tmp);
	original.resize(tmp);
	for(int i=1; i<n; i++) 
	{
		cin>>v[i];
		original[i] = v[i];
		v[i] += v[i-1];
	}

	st.init();
	
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int pos, val; cin>>pos>>val;
		//	cout<<"delta "<<val-original[pos]<<endl;
			st.update(val-original[pos], pos);
			original[pos] = val;
			
		//	st.print();
		}
		else
		{
			int a, b; cin>>a>>b;

			cout<<max((ll)0,st.query(a, b) - st.query(a-1, a-1))<<endl;
		}
	}
	
}
