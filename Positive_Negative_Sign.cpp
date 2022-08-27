//1294 - Positive Negative Sign
#include<stdio.h>
int main()
{
	long long t,n,m,p=1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		printf("Case %lld: %lld\n",p,((n/2)*m));
		p++;
	}
	return 0;
}
