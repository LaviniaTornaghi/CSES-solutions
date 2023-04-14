#include <bits/stdc++.h>
using namespace std;

struct Info
{
	int value, pos;
};

int n, q, tmp=1;
vector<Info> v;

struct SegTree
{
	vector<Info>tree;
	
	void init()
	{
		tree.resize(tmp*2);
		
		build(1, 0, tmp-1);
	}
	
	void build(int i, int l ,int r)
	{
		if(l==r)
		{
			tree[i] = v[i-tmp];
			return;
		}
		int mid = (l+r)/2;
		
		build(i*2, l , mid); build(i*2+1, mid+1, r);
		
		if(tree[i*2].value>=tree[i*2+1].value)
			tree[i] = tree[i*2];
		else
			tree[i] = tree[i*2+1];
	}
	
	void update(int pos) //gia indicizzato a +tmp
	{
		tree[pos] = v[pos-tmp];
		
		pos/=2;
		
		while(pos>0)
		{
			if(tree[pos*2].value>=tree[pos*2+1].value)
				tree[pos] = tree[pos*2];
			else
				tree[pos] = tree[pos*2+1];
			pos/=2;
		}
	}
	
	int bound;
	
	Info query(int i, int l, int r)
	{
		if(l==r)
			return tree[i];
			
		int mid = (l+r) / 2;
		
		if(tree[i*2].value >= bound)
			return query(i*2, l, mid);
		return query(i*2+1, mid+1, r);
	}
	
	void print()
	{
		for(int i=0; i<tmp*2; i++) cout<<tree[i].value<<" ";
		cout<<endl;
		for(int i=0; i<tmp*2; i++) cout<<tree[i].pos<<" ";
		cout<<endl;
	}
};

SegTree st;

int main()
{
	cin>>n>>q;
	
	while(tmp<n) tmp*=2;
	
	v.resize(tmp);
	for(int i=0; i<n; i++)
	{
		cin>>v[i].value;
		v[i].pos= i+1;
	}
	
	st.init();
	
	while(q--)
	{
		int p; cin>>p;
		st.bound = p;
		Info res = st.query(1, 0, tmp-1);
		
		if(res.value>=p)
			cout<<res.pos<<" ";
		else
		{
			cout<<"0 ";
			continue;
		}
		
		v[res.pos-1].value -= p;
		
		st.update((res.pos - 1) + tmp);
	}
}
