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

ll maxi,val[103],sum = 0;
int n;

bool check(ll v)
{
    ll cursum = sum;
    for(int i=1; i<=n; i++) cursum += (v - val[i]);
    return cursum >= sum;
}

int main()
{
    int q;

    scanf("%d", &q);

    for(int qq=1; qq<=q; qq++)
    {
        scanf("%d", &n);
        maxi = 0;

        for(int i=1; i<=n; i++)
        {
            scanf("%lld", &val[i]);
            if(maxi<val[i]) maxi = val[i];
            sum += val[i];
        }
        ll st = 1,en = 10000005,mid,res = -1;

        while(st<=en)
        {
            mid = (st + en) / 2;

            if(check(mid)) res = mid,en = mid - 1;
            else st = mid + 1;
        }

        printf("%lld\n", res);
    }

    return 0;
}