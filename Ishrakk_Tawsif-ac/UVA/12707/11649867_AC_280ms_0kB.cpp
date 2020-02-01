#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};


struct ST
{
    int s,e;

    bool operator <(const ST & x)const
    {
        if(x.e == e) return s>x.s;
        return e>x.e;
    }
};
ST p[100005],g[100005];

int main()
{
    int tc,n;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &n);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &p[i].s,&p[i].e);

        }
        sort(p,p+n);

        int cnt = 0,j;

        g[0].s = 0;
        g[0].e = 0;

        for(int i=0; i<n; i++)
        {
            for(j=0; j<=cnt; j++)
            {
                if(p[i].s>g[j].s && p[i].e<g[j].e)
                {
                    g[j] = p[i];
                    break;
                }
                if(j == cnt)
                {
                    cnt ++;
                    g[cnt] = p[i];
                    break;
                }
            }
        }

        pf("Case %d: %d\n", tt,cnt);
    }

    return 0;
}