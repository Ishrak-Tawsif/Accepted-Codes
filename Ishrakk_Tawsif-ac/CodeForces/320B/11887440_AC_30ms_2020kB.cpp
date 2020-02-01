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
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define mx                      5000005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

vector <pair<int,int> > graph;
int fl,vis[105];

int dfs(int sr,int ds)
{
    vis[sr] = 1;
    if(sr == ds) {return 1;}

    for(int i=0; i<graph.size(); i++)
    {
        int toa = graph[sr].first,tob = graph[sr].second;
        int frc = graph[i].first,frd = graph[i].second;

        if(((frc<toa && toa<frd) || (frc<tob && tob<frd)) && !vis[i])
        {
            if(dfs(i,ds)) return 1;
        }
    }
    return 0;
}

int main()
{
    int q,tp,u,v;
    sf(q);

    while(q--)
    {
        scanf("%d %d %d", &tp,&u,&v);
        if(tp == 1)
        {
            graph.pb(mp(u,v));
        }
        else
        {
            u--;
            v--;
            fl=0;
            mem(vis,0);
            fl = dfs(u,v);
            fl? pf("YES\n") : pf("NO\n");
        }
    }
    return 0;
}