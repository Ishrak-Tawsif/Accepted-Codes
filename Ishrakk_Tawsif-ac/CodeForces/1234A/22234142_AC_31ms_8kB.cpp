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

ll sum,val;

int main()
{
    int q,n;

    scanf("%d", &q);

    for(int qq=1; qq<=q; qq++)
    {
        scanf("%d", &n);
        sum = 0;

        for(int i=1; i<=n; i++)
        {
            scanf("%lld", &val);
            sum += val;
        }

        ll res = (sum / (ll)n) + (sum%(ll)n>0);
        printf("%lld\n", res);
    }
    return 0;
}