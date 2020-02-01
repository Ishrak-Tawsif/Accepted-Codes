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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007
#define endval                  1e-9

int ar[100005],ar2[100005],n,m;


bool check(ll val)
{
    ll a=0,b=m-1,cnt=0;

    while(b>=0 && a<n)
    {
        if(ar[a]>=ar2[b]) break;
        cnt += (ar2[b]-ar[a]);
        b--;
        a++;
    }
    return cnt<=val;
}

int main()
{

    scanf("%d %d", &n,&m);

    for(int i=0; i<n; i++) sf(ar[i]);
    for(int i=0; i<m; i++) sf(ar2[i]);

    sort(ar,ar+n);
    sort(ar2,ar2+m);

    ll st = 0,en = 1e14+5,mid,ans=0;

    while(st<=en)
    {
        mid = (st+en)>>1;
        if(check(mid)) ans=mid,en = mid-1;
        else st = mid+1;
    }
    pf("%lld\n", ans);

    return 0;
}