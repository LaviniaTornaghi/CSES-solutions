#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;
map<ll, bool> mp;
int n;

int main()
{
	cin>>n;

	for(int i=0; i<n; i++) 
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++)
	{
		vector<ll> ns(mp.size());
		int j=0;
		for(auto it : mp)
		{
			ns[j] = it.first + v[i];
			j++;
		}
		
		mp[v[i]]=1;
		
		for(j=0; j<ns.size(); j++) 
		{
			mp[ns[j]] = 1;
		}
	}
	cout<<mp.size()<<endl;
	
	for(auto it: mp) cout<<it.first<<" ";
}
