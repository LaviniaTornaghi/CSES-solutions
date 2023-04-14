#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, conta = 0;
	cin>>n;
	string s = to_string(n);
	
	while(s.size()>1)
	{
		int mx=0;
		for(int i=0; i<s.length(); i++)
			if(s[i]>mx)
				mx = s[i];
				
		n -= (mx-48);
		s = to_string(n);
		conta ++;
	}
	cout<<conta +1 ;
}
