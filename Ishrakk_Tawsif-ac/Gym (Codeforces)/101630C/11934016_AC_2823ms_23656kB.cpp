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

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int n,m,vis[100005],revvisid[100005],visid[100005];
vector <pair<int,int> >graph[2][100005],roadss[100005];
map<int,map<int,int> >id,revid;
//vector <pair<int,int> > roads[100005];

void dfs1(int sr)
{
    vis[sr] = 1;
//out(sr);
    for(int i=0; i<graph[0][sr].size(); i++)
    {
        int vv = graph[0][sr][i].first;
        int curid = graph[0][sr][i].second;

        if(!vis[vv]) visid[curid]=1,dfs1(vv);
    }
}

void dfs2(int sr)
{
    vis[sr] = 1;

    for(int i=0; i<graph[1][sr].size(); i++)
    {
        int vv = graph[1][sr][i].first;
        int curid = graph[1][sr][i].second;

        if(!vis[vv]) revvisid[curid]=1,dfs2(vv);
    }
}

void doclear()
{
    for(int i=0; i<100005; i++) roadss[i].clear();
    for(int i=0; i<100005; i++) graph[0][i].clear(),graph[1][i].clear();
}

int main()
{
    int tc;

    sf(tc);

    while(tc--)
    {
        scanf("%d %d", &n,&m);
        int u,v,curid=1,currevid=1;

        doclear();

        id.clear();
        revid.clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &u,&v);
            if(!id[u][v]) id[u][v] = curid;roadss[curid].pb(mp(u,v)),curid++;
            graph[0][u].pb(mp(v,id[u][v]));
            if(!revid[u][v]) revid[u][v] = currevid,currevid++;
            graph[1][v].pb(mp(u,revid[u][v]));
        }
        mem(vis,0);
        mem(visid,0);
        dfs1(1);
//out("1");
        mem(vis,0);
        mem(revvisid,0);
        dfs2(1);
//out(curid);
        int del = (m-(2*n)),cnt=0;

        for(int i=1; i<curid; i++)
        {
            if(!visid[i] && !revvisid[i] && cnt<del) pf("%d %d\n", roadss[i][0].first,roadss[i][0].second),cnt++;
        }

    }

    return 0;
}