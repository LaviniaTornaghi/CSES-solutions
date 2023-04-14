#include <bits/stdc++.h>
using namespace std;
 
int N, Q, l;
vector<int> v; // elementi
 
struct Query
{
	int a, b;
	int inx;
	
	bool operator <(const Query & other) const
	{
		if((a/l) != (other.a/l)) return (a/l)<(other.a/l); //blocchi diversi
		
		if((a/l)%2)
			return b>other.b;
		return b<other.b;
	}
};
 
vector<int> marca; //marca quanti elementi sono presenti
vector<int> sol; //contiene la soluzione ad ogni query
vector<Query> q;
unordered_map<int,int> mp;
int res;
 
int main()
{
	scanf("%d %d", &N, &Q);
	v.resize(N); sol.resize(Q);	q.resize(Q);
	l = 255;
	//input
	for(int i=0; i<N; i++)
	{
		scanf("%d", &v[i]);
		mp[v[i]] ++;
	}
	for(int i=0; i<Q; i++)
	{
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		q[i] = {a, b, i};
	}
	//rimappatura
	int conta = 0;
	for(auto it=mp.begin(); it!=mp.end(); it++)
	{
		it->second = conta;
		conta ++;
	}
	for(int i=0; i<N; i++) v[i] = mp[v[i]];
	marca.resize(mp.size());
	sort(q.begin(), q.end());
	
	int left = 0, right = 0;
	marca[v[0]] = 1;
	res = 1;

	for(auto [a, b, inx] : q)
	{
		while(right>b)
		{
			marca[v[right]] --;
			
			if(marca[v[right]] == 0) res--;
			right--;
		}
	
		while(right<b)
		{
			right++;
			marca[v[right]] ++;
			
			if(marca[v[right]] == 1) res++;
		}
		
		while(left<a)
		{	
			marca[v[left]]--;
			
			if(marca[v[left]] == 0) res--;
			left++;
		}
		while(left>a)
		{
			left--;
			marca[v[left]]++;
			
			if(marca[v[left]] == 1) res++;	
		}
		
		sol[inx] = res;
	}
	
	for(int i=0; i<Q; i++) cout<<sol[i]<<"\n";
}
