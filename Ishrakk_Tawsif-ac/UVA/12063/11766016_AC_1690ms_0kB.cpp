#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


ll n,k,minone,dp[65][101][65][65],pow2[65];

void gen_pow()
{
    pow2[0] = 1;
    //pow2[1] = 2;
    for(int i=1; i<=64; i++) pow2[i] = (ll)((pow2[i-1]*2)%k);
}

ll call(int pos,int val,int zero,int one)
{
    //if(one>(n/2)-1 || zero>(n/2)) return 0;
    if(pos == (n-1))
    {
        ll temp = (val+pow2[pos])%k;//cout<<val << " "<<pow2[pos]<<" "<<zero<<" "<<one<<endl;
        if(temp%k == 0 && zero == one+1) return 1;
        return 0;
    }
    if(dp[pos][val][zero][one] != -1) return dp[pos][val][zero][one];

    ll ans = 0,ans2=0;

    if(one<(n/2))ans = call(pos+1,(val+pow2[pos])%k,zero,one+1);
    if(zero<=(n/2))ans2 = call(pos+1,val,zero+1,one);

    return dp[pos][val][zero][one] = ans + ans2;
}

int main()
{
    int tc;
    sf(tc);


    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%lld %lld", &n,&k);
        //minone = -inf;
        ll temp = k,cnt=-1;
        if(!k){casepf(tt);pf("0\n");continue;}
        gen_pow();

        mem(dp,-1);
        ll res = call(0,0,0,0);
        casepf(tt);
        pf("%lld\n", res);
    }
}