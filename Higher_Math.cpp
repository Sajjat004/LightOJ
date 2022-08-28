#include<stdio.h>
int main()
{
    int i,t;
    int a,b,c;
    long long m,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a>b)
        {
            if(a>c)
            {
                n=a*a;
                m=(b*b)+(c*c);
            }
            else
            {
                n=c*c;
                m=(a*a)+(b*b);
            }
        }
        else
        {
            if(b>c)
            {
                n=b*b;
                m=(a*a)+(c*c);
            }
            else
            {
                n=c*c;
                m=(a*a)+(b*b);

            }
        }

        if(m==n)
            printf("Case %d: yes\n",i);
        else
            printf("Case %d: no\n",i);
    }
    return 0;
}
