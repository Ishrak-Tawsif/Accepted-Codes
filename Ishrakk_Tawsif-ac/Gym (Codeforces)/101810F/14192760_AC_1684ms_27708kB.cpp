#include <bits/stdc++.h>
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
#define loop1(var,start,till)   for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique_(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     7901
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

ll ar[100005],cont[2000007];
int vis[2000007];

int main()
{
    int tc,n,id = 0;

    sf(tc);

    while(tc --)
    {
        sf(n);
        ++id;
//        mem(vis,0);
//        mem(cont,0);

        for(int i=1; i<=n; i++) sfll(ar[i]),cont[ar[i]] ++;
        sort(ar,ar + n + 1);
        ll res = 0;
        for(int i=1; i<=n; i++)
        {
            ll now = ar[i];

            if(vis[now] != id)
            {//out(now);
                //vis[now] = id;
                for(ll j = now; j<=2000005; j+=now)
                {
                    if(vis[j] != id && cont[j])
                    {
                        res += (cont[j] * now);//cout<<now<<" "<<j<<" "<<cont[j]<<endl;
                        vis[j] = id;
                    }
                }
                vis[now] = id;
            }
        }

        for(int i=1; i<=n; i++) cont[ar[i]] = 0;
        pf("%lld\n", res);
    }
    return 0;
}