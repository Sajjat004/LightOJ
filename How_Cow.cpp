#include<stdio.h>
int main()
{
    int i,t,x1,x2,y1,y2,m,j,x,y;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);
        printf("Case %d:\n",i);
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&x,&y);
            if(x>=x1&&y>=y1&&x<=x2&&y<=y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

}
