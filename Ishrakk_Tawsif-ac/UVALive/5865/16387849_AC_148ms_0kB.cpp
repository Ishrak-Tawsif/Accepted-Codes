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
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int n;
vector <pair<int,ll> > graph[1003];
ll val[1003],x[1003],y[1003],res;
int vis[1003];

ll calc(ll x, ll y,ll xx, ll yy)
{
    x -= xx;
    y -= yy;

    return (x * x) + (y * y);
}

ll dikjstra(int sr,int ds)
{
    for(int i=0; i<1003; i++) vis[i] = 0,val[i] = -2e14;

    vis[sr] = 1;
    val[sr] = 0;
    set <pair<ll,int> > st;
    st.insert(mp(0,sr));

    while(!st.empty())
    {
        pair<ll,int> temp = *st.begin();
        st.erase(st.begin());

        int u = temp.second;
        ll cost = temp.first;

        if(u == ds) res = min(cost,res);

        for(auto x : graph[u])
        {
            int v = x.first;
            ll cc = x.second;

            if(!vis[v] || val[v]>max(cost,cc))
            {
                vis[v] = 1;
                val[v] = max(cost,cc);
                st.insert(mp(val[v],v));
            }
        }
    }
}

int main()
{//READ("in.txt");
    while(scanf("%d", &n) && n)
    {

        for(int i=0; i<1003; i++) graph[i].clear();

        int till = (n/20);

        int ind = 0;
        for(int i=1; i<=till; i++)
        {
            for(int j=1; j<=20; j++)++ind,scanf("%lld %lld", &x[ind], &y[ind]);
        }

        int ck = n % 20;//cout<<till<<" "<<ck<<endl;
        if(ck)
        {
            for(int i=1; i<=ck; i++)++ind,scanf("%lld %lld", &x[ind], &y[ind]);
        }
        till += ck;

        for(int i=1; i<=ind; i++)
        {
            for(int j=i+1; j<=ind; j++)
            {
                ll dis = calc(x[i],y[i],x[j],y[j]);
                graph[i].pb(mp(j,dis));
                graph[j].pb(mp(i,dis));
                //cout<<i<<" "<<j<<" "<<dis<<endl;
            }
        }

        res = 2e14;
        int sr,ds;

        scanf("%d %d", &sr,&ds);
        dikjstra(sr,ds);
        printf("%lld\n", res);
    }

    return 0;
}