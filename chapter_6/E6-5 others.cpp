# include<iostream>
# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
 
int l[100005],r[100005];
 
void link(int a,int b)
{
    r[a]=b,l[b]=a;
}
 
int main()
{
	freopen("input.txt","r",stdin);
    int n,m,op,x,y,flag,cas=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;++i)
            r[i]=(i+1)%(n+1),l[i]=i-1;
        r[0]=1,l[0]=n;
 
        flag=0;
        while(m--)
        {
            scanf("%d",&op);
            if(op==4)
                flag=!flag;
            else{
                scanf("%d%d",&x,&y);
                if(op==3&&r[y]==x)///方便下面的操作；
                    swap(x,y);
                if(op!=3&&flag)
                    op=3-op;
                if(op==1&&l[y]==x)
                    continue;
                if(op==2&&r[y]==x)
                    continue;
 
                int lx=l[x],rx=r[x],ly=l[y],ry=r[y];
                if(op==1){
                    link(lx,rx);
                    link(ly,x);
                    link(x,y);
                }else if(op==2){
                    link(lx,rx);
                    link(y,x);
                    link(x,ry);
                }else{
                    if(r[x]==y)
                        link(lx,y),link(y,x),link(x,ry);
                    else
                        link(lx,y),link(y,rx),link(ly,x),link(x,ry);
                }
            }
        }
        int k=0;
        long long ans=0;
        for(int i=1;i<=n;++i){
            k=r[k];
            if(i&1)
                ans+=k;
        }
        if(flag&&n%2==0)
            ans=(long long)n/2*(n+1)-ans;
        printf("Case %d: %lld\n",++cas,ans);
    }
    return 0;
}
