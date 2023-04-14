#include <bits/stdc++.h> 
using namespace std;

int N=1, tmp, Q, d;
vector<vector<long long>> v; // 0 andare avanti, 1 indietro

struct Segtree
{
	vector<long long>tree;
	int qs, qe;
	
	void build(int i, int l, int r)
	{
		if(l==r)
		{
			tree[i] = v[d][i-N];
			return;
		}
		int mid = (l+r)/2;
		build(i*2, l, mid); build(i*2+1, mid+1, r);
		tree[i] = min(tree[i*2], tree[i*2+1]);
	}
	
	void update(int pos, int val) //gia alla foglia
	{
		tree[pos] = val;
		pos/=2;
		while(pos>0)
		{
			tree[pos] = min(tree[pos*2], tree[pos*2+1]);
			pos/=2;
		}
	}
	
	long long query(int i, int l, int r)
	{
		if(l>qe || r<qs) return INT_MAX;
		if(l>=qs && r<=qe)
			return tree[i];
		int mid=(l+r)/2;
		return min(query(i*2, l, mid), query(i*2+1, mid+1, r));
	}
};

Segtree st[2];

int main()
{
	cin>>tmp>>Q;
	
	while(tmp>N) N*=2;
	v.resize(2, vector<long long>(N, INT_MAX));
	for(int i=0; i<tmp; i++)
	{
		cin>>v[0][i];
		v[1][i] = v[0][i] -i -1;
		v[0][i] = v[0][i] +i +1;
	}
	
	st[0].tree.resize(N*2, INT_MAX);
	st[1].tree.resize(N*2, INT_MAX);
	d=1; st[1].build(1, 0, N-1);
	
	while(Q--)
	{
		int tipo;
		cin>>tipo;
		if(tipo==1)
		{
			int val, pos;
			cin>>pos>>val;
			st[0].update(pos-1+N, val+pos);
			st[1].update(pos-1+N, val-pos);
		}
		else
		{
			int pos;
			cin>>pos;
			pos--;
			st[0].qs = pos; st[0].qe = tmp-1;
			st[1].qs = 0; st[1].qe = pos -1;
			cout<<min(st[0].query(1, 0, N-1)-pos-1, st[1].query(1,0,N-1)+pos+1)<<endl;
		}
	}
}

