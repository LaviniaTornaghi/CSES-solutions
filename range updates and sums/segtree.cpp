#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, q, tmp=1;
vector<ll> v;

struct SegTree
{
	vector<ll> tree;
	vector<ll> lazy;
	vector<ll> set; //dibase -1
	int sq, eq, value;
	
	void init()
	{
		tree.resize(2*tmp);
		lazy.resize(2*tmp);
		set.resize(2*tmp, -1);
		
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
		tree[i] = tree[i*2] + tree[i*2+1];
	}
	
	void setr(int s, int e, int v)
	{
		sq = s; eq = e; value = v;
		setrange(1, 0, tmp-1);
	}
	
	void setrange(int i, int l, int r)
	{
		cout<<i<<"\n";
		if(set[i] != -1) //se ci sono degli update lazy
		{
			tree[i] = (r-l+1) * set[i];
			if(l!=r)
			{
				set[i*2] = set[i];
				set[i*2+1] = set[i];
				lazy[i*2] = lazy[i*2+1] = 0;
			}
			set[i] = -1;
		}
		if(lazy[i]!=0)
		{
			tree[i] += lazy[i] *(r-l+1);
			if(l!=r)
			{
				lazy[i*2] = lazy[i];
				lazy[i*2+1] = lazy[i];
			}
			lazy[i] = 0;
		}
		
		if(l>eq || r<sq)
			return;
			
		if(l>=sq && r<=eq)
		{
			tree[i] = value;
			
			if(l!=r)
			{
				set[i*2] = value;
				set[i*2+1] = value;
				lazy[i*2] = lazy[i*2+1] = 0;
			}
			return;
		}
		int mid = (l+r)/2;
		setrange(i*2, l, mid); setrange(i*2+1, mid+1, r);
		tree[i] = tree[i*2] + tree[i*2+1];
	}
	
	
	
	void print()
	{
		cout<<"tree\n";
		for(int i=0; i<tmp*2; i++) cout<<tree[i]<<" ";
		cout<<endl;
		cout<<"lazy\n";
		for(int i=0; i<tmp*2; i++) cout<<lazy[i]<<" ";
		cout<<endl;
		cout<<"set\n";
		for(int i=0; i<tmp*2; i++) cout<<set[i]<<" ";
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
	st.print();
	
	st.setr(1, 2, 3);
	
	st.print();
	
	while(q--) //occhio a ridurre a 0-based
	{
		int type; cin>>type;
		
		if(type==1)// increase [a,b] by value
		{
			int a, b, value; cin>>a>>b>>value;
			
		}
		else if(type==2) // set [a,b] to value
		{
			int a, b, value; cin>>a>>b>>value;
		}
		else // sum of [a,b]
		{
			int a, b; cin>>a>>b; a--; b--;
		}
	}
}
