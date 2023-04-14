#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N; cin>>N;
	vector<int> v(N);
	for(auto &i : v) cin>>i;

	deque<pair<int,int>> dq; // first inx  second val
	
	for(int i=0;  i<N; i++)
	{
		while(!dq.empty())
		{
			if(dq.back().second >=  v[i])
				dq.pop_back();
			else
				break;
		}

		if(!dq.empty()) cout<<dq.back().first<<" ";
		else cout<<"0 ";

		dq.push_back({i+1, v[i]});
	}
}
