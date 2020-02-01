#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

ll sum[150005];

int main()
{//WRITE("in.txt");


    int n,k;
    ll temp;

    while(~sf(n))
    {
        sf(k);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld", &temp);
            sum[i] = sum[i-1] + temp;
        }

        ll ans = inf,ind=-1;
        for(int i=0; i+k<=n; i++)
        {
            if(ans>sum[i+k]-sum[i]) ans = sum[i+k]-sum[i],ind=i+1;
            //cout<<ans<<endl;
        }
        pf("%d\n", ind);
    }

    return 0;
}