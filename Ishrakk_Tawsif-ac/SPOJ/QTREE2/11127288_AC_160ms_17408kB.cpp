#include<bits/stdc++.h>
using namespace std;

int dirx[8]={0,0,1,-1,1,1,-1,-1};
int diry[8]={1,-1,0,0,1,-1,1,-1};

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      10000007+5
#define mod                     1000000007


vector < pair<int,ll> > graph[10005];
int par[10005],sparse[10005][18],level[10005],n,vis[10005];
ll diss[10005];

void dfs(int cur,int parent,int lev)
{
    par[cur] = parent;
    level[cur] = lev;

        for(int i=0; i<graph[cur].size(); i++)
        {
            int vv = graph[cur][i].first;
            if(vv == parent) continue;
            dfs(vv,cur,lev+1);
        }
}

void build()
{
    dfs(1,-1,1);

    mem(sparse,-1);

    for(int i=1; i<=n; i++) sparse[i][0] = par[i];

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n;i++)
        {
            sparse[i][j] = sparse [sparse[i][j-1]][j-1];
        }
    }
}

int query(int p,int q)
{
    int log;

    if(level[p]<level[q]) swap(p,q);

    for(log=1; (1<<log)<=level[p]; log++);
    log--;

    for(int i=log; i>=0; i--)
    {
        if(level[p]-(1<<i)>=level[q])
        {
            p = sparse[p][i];
        }
    }

    if(p == q) return p;

    for(int i=log; i>=0; i--)
    {
        if(sparse[p][i] != -1 && sparse[p][i] != sparse[q][i])
            p = sparse[p][i], q = sparse[q][i];
    }

    return par[p];
}

void dfs2(int cur)
{
    vis[cur] = 1;
    //diss[cur] = curdis;
//cout<<cur<<endl;
        for(int i=0; i<graph[cur].size(); i++)
        {
            int vv = graph[cur][i].first;
            if(!vis[vv])
            {
                diss[vv] = diss[cur] + graph[cur][i].second;
                dfs2(vv);
            }
        }
}

int main()
{//WRITE("in.txt");
    int tc,u,v;
    ll cs;

    sf(tc);

    while(tc--)
    {
        for(int i=0; i<10005; i++) graph[i].clear();
        scanf("%d", &n);
        for(int i=0; i<(n-1); i++)
        {

            scanf("%d %d %lld", &u,&v,&cs);
            graph[u].pb(mp(v,cs));
            graph[v].pb(mp(u,cs));

        }

        build();
        diss[1] = 0;
        mem(vis,0);
        dfs2(1); /// calculating distance of all node from root node

        string str;

        while(cin>> str)
        {
            if(str == "DONE") break;
            else if(str == "DIST")
            {
                scanf("%d %d", &u,&v);
                int lcauv = query(u,v);//cout<<diss[u]<<" " << diss[v] <<endl;
                ll res = (diss[u] + diss[v]) - (2*diss[lcauv]);
                pf("%lld\n", res);
            }
            else if(str == "KTH")
            {
                int k;
                scanf("%d %d %d", &u,&v,&k);
                int lcauv = query(u,v);
                k--;
                int log;
//cout<<level[u]<<" ........... " << level[lcauv] <<endl;

                if(level[u]- level[lcauv]>=k)
                {
                    ///kth parent of u

                    for(log=1; (1<<log)<=k; log++);
                    log--;

                    int tempu=u;//cout<<log<<"..."<<endl;;
                    while(k >= 1)
                    {
                        tempu = sparse[tempu][log];
                        //if(log == 1) break;
                        k = k - (1<<log);
                        for(log=0; (1<<log)<=k; log++);
                        log--;//cout<<k<<" " << log << " " <<tempu<<endl;
                    }
                    cout<<tempu <<endl;
                }
                else
                {
                    int disuv = (level[u]-level[lcauv]) + (level[v]-level[lcauv]);
                    k = disuv - k;

                    for(log=1; (1<<log)<=k; log++);
                    log--;

                    int tempv=v;
                    while(k >= 1)
                    {
                        tempv = sparse[tempv][log];
                        //if(log == 1) break;
                        k = k - (1<<log);
                        for(log=0; (1<<log)<=k; log++);
                        log--;//cout<<k<<" " << log << " " <<tempv<<endl;
                    }
                    cout<< tempv <<endl;
                }
            }
        }

        pf("\n");
    }

    return 0;
}


/*
9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/