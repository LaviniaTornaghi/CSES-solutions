#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, S; cin>>N>>S;
	vector<int> v(N);
	for(int i=0; i<N; i++) cin>>v[i];

	int a=0, b=1, sum = v[0],  res =0;

	while(a<N  && b<N)
	{
		while(sum<S  && b<N)
		{
			sum += v[b];
			b++;
		//	cout<<"lol "<<b<<" "<<sum<<endl;
		}

		while(sum>S && a<N-1)
		{
			sum -= v[a];
			a++;
		}
	//	cout<<" val "<<sum<<" "<<a<<" "<<b<<endl;

		if(sum == S)
		{
		//	cout<<a<<" "<<b<<endl;
			res ++;
			sum -= v[a];
			a++;
		}

		if(a==N-1 && b == N)break;
	}
	cout<<res;
}
