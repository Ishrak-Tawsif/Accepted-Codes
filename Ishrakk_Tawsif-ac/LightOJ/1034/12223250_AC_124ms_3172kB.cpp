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
#define mx                      20005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,m,vis[mx];
vector <int> graph[mx],topsort;

void dfs(int curnode)
{
    vis[curnode] = 1;
    for(int i=0; i<graph[curnode].size(); i++)
    {
        int vv = graph[curnode][i];
        if(!vis[vv]) dfs(vv);
    }
    topsort.pb(curnode);
}

void clearall()
{
    topsort.clear();

    for(int i=0; i<mx; i++)
    {
        vis[i] = 0;
        graph[i].clear();
    }
}

int main()
{
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {

        clearall();

        scanf("%d %d", &n, &m);

        int u,v;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
        }

        int res = 0;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }

        mem(vis,0);

        int sz = topsort.size();
        for(int i=sz-1; i>=0; i--)
        {
            int vv = topsort[i];
            if(!vis[vv])
            {
                res ++;
                dfs(vv);
            }
        }

        casepf(tt);
        out(res);
    }

    return 0;
}

/*
3

6 7
2 5
4 1
5 2
5 3
5 4
5 6
6 5

11 10
6 1
11 6
6 4
8 2
8 9
1 5
5 2
11 3
1 9
6 11

7 13
1 6
2 1
2 3
2 6
3 1
3 5
4 6
4 7
5 4
6 1
7 1
7 2
7 4


///

output :

Case 1: 1
Case 2: 4
Case 3: 1

*/