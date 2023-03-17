#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	long long a;
	scanf("%lld",&n);
	a=n*(n+1)/2;
	for(int i=0; i<n-1; i++) 
	{
		int b;
		scanf("%d", &b);
		a-=b;
	}
	printf("%lld",a);
}
