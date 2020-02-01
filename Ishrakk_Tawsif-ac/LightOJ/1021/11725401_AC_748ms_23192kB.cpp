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

int ar[21],base,len,lim,k;
ll dp[21][1<<17];
string str;

ll call(int rem,int mask)
{
    if(mask == lim) {if(rem%k == 0) return 1;else return 0;}
    if(dp[rem][mask] != -1) return dp[rem][mask];

    ll ans = 0;

    for(int i=0; i<len; i++)
    {
        if(!(mask & 1<<i))
        {
            int val = ((rem*base) + ar[i])%k;
            ans += (call(val%k,mask | 1<<i));
        }
    }
    return dp[rem][mask] = ans;
}

int main()
{
    int tc;
    sf(tc);//cin.ignore();
    for(int tt=1; tt<=tc; tt++)
    {
        cin>> base>> k;
        cin>> str;

        len = str.length();
        for(int i=0; i<len; i++)
        {
            if(str[i]>='0' && str[i]<='9') ar[i] = str[i]-'0';
            else ar[i] = (str[i]-'A') + 10;//out(ar[i]);
        }
        mem(dp,-1);
        lim = (1<<len)-1;
        ll res = call(0,0);
        casepf(tt);
        pf("%lld\n", res);
    }
    return 0;
}