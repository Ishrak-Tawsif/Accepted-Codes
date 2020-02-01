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
    #define all(a)                  (a.begin(),a.end())
    #define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
    #define mx                      20005
    #define mod                     1000000007
     
    template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
    template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
     
    string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
    ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}
     
    /* ...........................................................................................................*/
     
    int cost[203][203],par[203],n,m,ind[205][205],cnt1[2],konta[2],koto[2],vis[mx],id;
     
    struct ST
    {
        int u,v,cs;
        bool operator <(const ST & x)const
        {
            return cs<x.cs;
        }
    };
    vector <ST> vv,temp,graph;
     
    int findpar(int p)
    {
        if(par[p] == p) return p;
        else return par[p] = findpar(par[p]);
    }
     
    int mst()
    {
        temp = vv;
        for(int i=1; i<=n; i++) par[i] = i;
        sort(temp.begin(),temp.end());
     
        int cnt=0,tot=0;
        for(int i=0; i<temp.size(); i++)
        {
            int u = temp[i].u;
            int v = temp[i].v;
     
            int paru = findpar(u);
            int parv = findpar(v);
     
            if(paru != parv)
            {
                par[paru] = parv;
                tot += temp[i].cs;
                cnt ++;
                graph.pb(temp[i]);
                if(cnt == (n-1)) break;
            }
        }
        return tot;
    }
     
    void clearall()
    {
        temp.clear();
        vv.clear();
        graph.clear();
        id = 0;
        for(int i=0; i<205; i++)
        {
            vis[i] = 0;
            for(int j=0; j<205; j++)
            {
                ind[i][j] = -1;
            }
        }
    }
     
    int mst2(int curu,int curv,int curcs,int update)
    {
        int res = 0;
        for(int i=0; i<graph.size(); i++)
        {
            int u = graph[i].u,v = graph[i].v;
            int indnow = ind[u][v];
            graph[i].cs = vv[indnow].cs;
            res += graph[i].cs;
        }
     
        temp = graph;
        ST get;
        get.u = curu,get.v = curv,get.cs = curcs;
        temp.pb(get);
     
        graph.clear();
     
        for(int i=1; i<=n; i++) par[i] = i;
        sort(temp.begin(),temp.end());
        int cnt=0,tot=0;
        for(int i=0; i<temp.size(); i++)
        {
            int u = temp[i].u;
            int v = temp[i].v;
     
            int paru = findpar(u);
            int parv = findpar(v);
     
            if(paru != parv)
            {
                par[paru] = parv;
                tot += temp[i].cs;
                cnt ++;
                graph.pb(temp[i]);
                if(cnt == (n-1)) break;
            }
        }
        return tot;
    }
     
    int main()
    {//WRITE("in.txt");
        int cs,tc;
     
        sf(tc);
     
        for(int tt=1; tt<=tc; tt++)
        {
     
            scanf("%d %d", &n,&m);
     
            ST get;
     
            casepf(tt);
            clearall();
     
            for(int i=1; i<=n; i++) par[i] = i;
            int cnt = 0,res,check=0,update;
           
                for(int i=0; i<m; i++)
                {
                    update = 1;
                    scanf("%d %d %d", &get.u,&get.v,&get.cs);
     
                    if(ind[get.u][get.v] == -1)
                    {
                        ind[get.u][get.v] = vv.size();
                        ind[get.v][get.u] = vv.size();
                        vv.pb(get);
                    }
                    else
                    {
                        int indnow = ind[get.u][get.v];
                        if(vv[indnow].cs>get.cs) vv[indnow].cs = get.cs,update=0;
                    }
     
                    if(!check)
                    {
                        int paru = findpar(get.u);
                        int parv = findpar(get.v);
                        if(paru != parv)
                        {
                            par[paru] = parv;
                            cnt ++;
                        }
                        if(cnt == (n-1)) {check = 1; res = mst(); pf("%d\n",res); continue;}
                    }
     
                if(!check) pf("-1\n");
     
                else
                {
                    res = mst2(get.u,get.v,get.cs,update);
                    pf("%d\n",res);
                }
            }
        }
        return 0;
    }
     
    /*
    4 3
    1 2 2
    3 4 4
    3 2 2
     
    */