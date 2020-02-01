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
    #define mx                      105
    #define mod                     1000000007
     
    template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
    template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
     
    string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
    ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}
     
    /* ...........................................................................................................*/
     
    ///hints ::: perform two dfs, "clockwise" and "counterclockwise" and take the minimum of them.
     
    struct ST
    {
        int v,cst;
     
        bool operator <(const ST & x)const
        {
            return cst<x.cst;
        }
    };
    vector <ST> graph[mx];
    int n,vis[mx],mark[3*mx],edgeid[mx][mx],dis[mx];
     
    int dfs(int cur,int id,int par)
    {
        if(cur == 1) return 0;
        vis[cur] = id;
        for(int i=0; i<graph[cur].size(); i++)
        {
            int vv = graph[cur][i].v;
            if(vv != par) {vis[vv] = id;return dfs(vv,id,cur) + graph[cur][i].cst;}
        }
    }
     
     
    int main()
    {//WRITE("in.txt");
        int tc;
     
        sf(tc);
     
        ST get;
        for(int tt=1; tt<=tc; tt++)
        {
            sf(n);
     
            for(int i=1; i<mx; i++) graph[i].clear();
            for(int i=0; i<n; i++)
            {
                int u,v,c;
                scanf("%d %d %d", &u,&v,&c);
                get.cst = 0;
                get.v = v;
                graph[u].pb(get);
                //edgeid[u][v] = ++idd;
                get.cst = c;
                get.v = u;
                graph[v].pb(get);
                //edgeid[v][u] = ++idd;
            }
     
            int res = 0;
     
            mem(vis,0);
            res = min(dfs(graph[1][0].v,1,1) + graph[1][0].cst,dfs(graph[1][1].v,2,1) + graph[1][1].cst);
     
            casepf(tt);
            pf("%d\n", res);
        }
     
        return 0;
    }