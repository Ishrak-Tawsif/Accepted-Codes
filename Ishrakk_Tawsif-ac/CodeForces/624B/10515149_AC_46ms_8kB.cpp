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
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

ll ar[29],last,ans;

int main()
{
    int n;
    sf(n);
    last = intinf;
    ans=0;

        for(int i=0; i<n; i++) scanf("%lld", &ar[i]);
        sort(ar,ar+n);

        for(int i=n-1; i>=0; i--)
        {
            if(ar[i]<last)ans += ar[i],last = ar[i];
            else if(ar[i] == last) ans+= (ar[i]-1<0)? 0 : ar[i]-1,last=ar[i]-1;
            else ans += (last-1<0)? 0 : last-1,last--;
        }
        pf("%lld\n",ans);

    return 0;
}