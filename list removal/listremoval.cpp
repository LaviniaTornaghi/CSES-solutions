#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

struct SegTree
{
	vector<int> tree;
	
	void init()
	{
		tree.resize(2*n);
		build(1, 0, n-1);
	}
	
	void build(int inx, int l, int r)
	{
		if(l==r)
		{
			tree[inx] = 1;
			return;
		}
		int mid = (l+r)/2;
		build(inx*2, l, mid);
		build(inx*2+1, mid+1, r);
		tree[inx]= tree[inx*2]+tree[inx*2+1];
	}
	
	void update(int pos)
	{
		assert(tree[pos]==1);
		tree[pos]=0;
		pos/=2;
		while(pos>0)
		{
			tree[pos]--;
			pos /=2;
		}
	}
	
	int k;
	int lb(int inx, int before)
	{
		if(inx>=n)
			return inx;
		
		if(before+tree[inx*2]>=k)//a sinistra ci sono abbastanza elementi
		{
			return lb(inx*2, before);
		}
		else 
		{
			return lb(inx*2+1, before + tree[inx*2]);
		}
	}
	
	void print()
	{
		for(int i=1; i<2*n; i++) cout<<tree[i]<<" ";
	}
};

SegTree st;
int main()
{
	cin>>n;
	int tmp = n;
	n=1;
	while(n<tmp) n *=2;
	st.init();
	v.resize(tmp);
	map <int, int> mp;
	for(int i=0; i<tmp; i++){ 
		cin>>v[i];
		mp[i] = v[i];
	}
	vector<int> res(tmp);
	
	for(int i=0; i<tmp; i++)
	{
		int K;
		cin>>K;
		st.k = K;
		int val = st.lb(1, 0);
		res[i] = mp[val-n];
		st.update(val);
	}
	
	for(auto it: res) cout<<it<<" ";
}
