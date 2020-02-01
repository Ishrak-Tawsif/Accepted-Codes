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
#define ll                      unsigned long long int
#define mx                      1000005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int holes[1000005];

int main()
{
    int n,m,k,temp,u,v,fl=0,ans;
        sf(n);
        sf(m);
        sf(k);

            loop(i,0,m)
            {
                sf(temp);
                holes[temp] = 1;
            }

            ans=1;
            if(holes[1] == 1) {fl=1; ans=1;}

            loop(i,0,k)
            {
                sf(u);
                sf(v);

                if(u != ans && v!=ans) continue;

                if(fl == 1) continue;
                if(holes[v] == 1 && u==ans &&!fl)
                {
                    fl=1;
                    ans=v;
                }
                else if(holes[u]==1 && v==ans && !fl)
                {
                    fl=1;
                    ans=u;
                }
                else
                {
                    (ans==u)? ans=v : ans=u;
                }
            }

            pf("%d\n",ans);
    return 0;
}