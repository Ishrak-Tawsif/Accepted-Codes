#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      557
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

bitset <mx> isprime;
vector <int> prime;
int n,qq,dp[5005][5005],vis[5005];

void sieve()
{
    isprime[1] = 1;
    for(int i=3; i<mx; i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
        }
    }

    prime.pb(1);
    prime.pb(2);
    for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb(i);
}

/*int call(int tot,int kt)
{//out(tot);
    if(tot>q) return 2e9;
    if(tot == q) {return kt;}
    if(dp[tot][kt] != -1) return dp[tot][kt];

    int ans = 0,res = 2e9;

    for(int i=0; i<n; i++)
    {//out(prime[i]);
        ans = call(tot+prime[i],kt+1);
        res = min(ans,res);//cout<<tot<<" "<<res<<endl;
    }///out(res);
    return dp[tot][kt] = res;
}*/

int bfs()
{
    queue <pair<int,int> >q;
    for(int i=0; i<n; i++) q.push(mp(prime[i],1));

    while(!q.empty())
    {
        pair <int,int> pp = q.front();
        q.pop();

        int koyta = pp.second;
        int sum = pp.first;

        if(sum == qq) return koyta;

        for(int i=0; i<n; i++)
        {
            int vv = prime[i] + sum;

            if(vv<=qq && !vis[vv])
            {
                vis[vv] = 1;
                q.push(mp(vv,koyta+1));
            }
        }
    }
}

int main()
{
    sieve();//out(prime.size());


    int tc;

    sf(tc);

    while(tc--)
    {
        scanf("%d %d", &n,&qq);
        //mem(dp,-1);
        mem(vis,0);
        int res = bfs();
        out(res);
    }
    return 0;
}