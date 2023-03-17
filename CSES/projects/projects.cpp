#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, tmp=1; // N= elementi del vector, tmp = potenza di due piu vicina
int n; // processi in input

struct Info
{
	int a, b, p;
	
	bool operator <(const Info & other)const
	{
		return a<other.a;
	}
};

struct SegTree
{
	vector<ll> tree;
	int sq, eq;
	
	void init()
	{
		tree.resize(tmp*2);
	}
	
	void update(int pos, ll value) //pos gia tmp + pos
	{
		tree[pos] = max(tree[pos], value);
		pos /= 2;
		
		while(pos>0)
		{
			tree[pos] = max(tree[pos], value);
			pos /= 2;
		}
	}
	
	ll query(int i, int l, int r)
	{
		if(l>eq || r<sq)
			return 0;
			
		if(l>=sq && r<=eq)
			return tree[i];
			
		int mid = (l+r) / 2;
		
		return max(query(i*2, l, mid), query(i*2+1, mid+1, r));
	}
	
	void print()
	{
		for(int i=0; i<tmp*2; i++) cout<<tree[i]<<" ";
		cout<<endl;
	}
};

SegTree st;
vector<Info> v;
map<ll,int> mp;
int safe;

int main()
{
	cin>>n;
	int safe=0; //fine piu lontana
	for(int i=0; i<n; i++)
	{
		Info info;
		cin>>info.a>>info.b>>info.p;
		v.push_back(info);
		mp[info.a] = 1;
		mp[info.b] = 1;
		if(info.b >safe) safe = info.b;
	}
	mp[safe+1] = 1;
	
	sort(v.begin(), v.end());
	
	int inx = 0;
	for(auto it: mp)
	{ 
		mp[it.first] = inx;
		inx++;
	}
	N = mp.size();
	
	while(tmp<N) tmp *=2;
	
	st.init();
	
	for(int i= n-1; i>=0; i--)
	{
		st.sq =mp[v[i].b] + 1;
		st.eq = tmp-1;
		
		ll res = st.query(1, 0, tmp-1);
		st.update(mp[v[i].a]+tmp, res+ v[i].p);
	}
	cout<<st.tree[1];
}
