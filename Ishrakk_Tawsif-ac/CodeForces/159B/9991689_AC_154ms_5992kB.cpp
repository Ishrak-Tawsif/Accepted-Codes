#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

int marker[1003][1003],sz[1003];

int main()
{
    int mar,cap,u,v,ans=0,ans2=0;

        sf(mar);
        sf(cap);

            loop(i,0,mar)
            {
                scanf("%d %d", &u,&v);
                marker[v][u]++;
                sz[v]++;
            }

            loop(i,0,cap)
            {
                scanf("%d %d", &u,&v);

                    if(sz[v]>0)
                    {
                        ans++;
                        sz[v]--;
                    }
                    if(marker[v][u]>0)
                    {
                        ans2++;
                        marker[v][u]--;
                    }
            }
            pf("%d %d\n", ans,ans2);
    return 0;
}