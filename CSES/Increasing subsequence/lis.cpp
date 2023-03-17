#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db if(eq == 7)

int N, n, tmp=1; //N elementi distinti, n nell'array e tmp la potenza di due superiore
vector<int> v;
map<int,int> mp;

struct SegTree
{
	vector<ll> tree;
	
	void init()
	{
		tree.resize(tmp*2);
	}
	
	void update(int pos,ll value) //posizione gia = array + tmp
	{
		tree[pos] = max(tree[pos], value);
		pos /= 2;
		
		while(pos)
		{
			tree[pos] = max(tree[pos], value);
			pos/=2;
		}
	}
	int sq=0, eq;
	
	ll query(int i, int l, int r)
	{
		if(l>eq || r<sq) return INT_MIN;
		
		
		if(l>=sq && r<= eq)
		{
			 return tree[i];
		}
		
		int mid = (l+r) /2;
		
		return max(query(i*2, l, mid), query(i*2+1, mid+1, r));
	}
	
	void print()
	{
		for(int i=0; i<2*tmp; i++) cout<<tree[i]<<" ";
		cout<<endl;
	}
};

SegTree st;

int main()
{
	cin>>n;
	v.resize(n);
	
	for(int i=0; i<n; i++)
	{
		cin>>v[i];
		mp[v[i]]++;
	}
	int conta = 0;
	for(auto item = mp.begin(); item != mp.end(); item++)
	{
		item->second = conta;
		conta++;
	}
	
	N = mp.size();
	
	while(tmp < N) tmp*=2;
	
	st.init();
	
	for(int i=0; i<n; i++)
	{
		ll value = v[i];
		if(mp[value] == 0)
		{
			st.update(tmp+mp[value], 1);
			continue;
		}
		st.eq = mp[value]-1;

		ll res = st.query(1, 0, tmp-1);
		
		st.update(tmp+mp[value], res + 1);
	}
	cout<<st.tree[1];
}
