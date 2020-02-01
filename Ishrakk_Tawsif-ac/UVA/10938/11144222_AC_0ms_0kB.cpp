///lca

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

int n;
int par[5005],sparse[5005][18],level[5005],vis[5005],diss[5005];
vector <int> graph[5005];

void dfs(int cur,int parent,int lev)
{
    par[cur] = parent;
    level[cur] = lev;

    for(int i=0; i<graph[cur].size(); i++)
    {
        int vv = graph[cur][i];

        if(vv == parent) continue;

        dfs(vv,cur,lev+1);
    }
}

void build()
{
    mem(sparse,-1);
    dfs(1,-1,1);

    for(int i=1; i<=n; i++) sparse[i][0] = par[i];

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sparse[i][j-1] != -1)sparse[i][j] = sparse[sparse[i][j-1]][j-1];
        }
    }
}

int query(int p,int q)
{
    int log;

    if(level[p]<level[q]) swap(p,q);

    for(log=0;(1<<log)<=level[p]; log++);
    log--;

    for(int i = log; i>=0; i--)
    {
        if(level[p]-(1<<i)>=level[q])
            p = sparse[p][i];
    }

    if(p == q) return p;

    for(int i = log; i>=0; i--)
    {
        if(sparse[p][i] != -1 && sparse[p][i] != sparse[q][i])
            p = sparse[p][i],q=sparse[q][i];
    }

    return par[p];
}

void dfs2(int sr)
{
    vis[sr] = 1;


        for(int i=0; i<graph[sr].size(); i++)
        {
            int vv = graph[sr][i];

            if(!vis[vv])
            {
                diss[vv] = diss[sr] + 1;
                dfs2(vv);
            }
        }
}

void init()
{
    for(int i=0; i<5005; i++) graph[i].clear(),vis[i]=0;
}

int main()
{//WRITE("in.txt");
    int u,v;
    while(sf(n) == 1 && n)
    {
        init();

        for(int i=0; i<(n-1); i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        build();
        diss[1] = 0;
        vis[1] = 1;
        dfs2(1);

        int q;
        sf(q);

        while(q--)
        {
            scanf("%d %d", &u,&v);
            int lcauv = query(u,v);
            int disuv = (diss[u] + diss[v]) - (2*diss[lcauv]);
            if(disuv&1)
            {
                ///not possible
                disuv /= 2;
                int tmpdisuv=disuv,resu,resv;
                ///for u
                if(disuv<=level[u]-level[lcauv])
                {
                    int log,temp=u;
//cout<<" ............. \n";
                    for(log = 0; (1<<log)<=tmpdisuv; log++);
                    log--;

                    while(tmpdisuv>=1)
                    {
                        temp = sparse[temp][log];
                        tmpdisuv = tmpdisuv - (1<<log);

                        for(log=0; (1<<log)<=tmpdisuv; log++);
                        log--;
                    }

                    resu = temp;
                }
                else
                {
                    int lafdisi = level[u]-level[lcauv];
                    int bakiase = disuv-lafdisi;
                    int tmpdisuv = (level[v]-level[lcauv])-bakiase;
                    int log,temp=v;

                    for(log=0; (1<<log)<=tmpdisuv; log++);
                    log--;

                    while(tmpdisuv>=1)
                    {
                        temp = sparse[temp][log];
                        tmpdisuv = tmpdisuv-(1<<log);

                        for(log=0; (1<<log)<=tmpdisuv; log++);
                        log--;
                    }
                    resu = temp;
                }

                ///for v
//cout<<"v"<<" "<<level[v]-level[lcauv]<<endl;
                tmpdisuv = disuv;
                if(disuv<=level[v]-level[lcauv])
                {
                    int log,temp=v;

                    for(log = 0; (1<<log)<=tmpdisuv; log++);
                    log--;

                    while(tmpdisuv>=1)
                    {
                        temp = sparse[temp][log];
                        tmpdisuv = tmpdisuv - (1<<log);

                        for(log=0; (1<<log)<=tmpdisuv; log++);
                        log--;
                    }

                    resv = temp;
                }
                else
                {
                    int lafdisi = level[v]-level[lcauv];
                    int bakiase = disuv-lafdisi;
                    int tmpdisuv = (level[u]-level[lcauv])-bakiase;
                    int log,temp=u;

                    for(log=0; (1<<log)<=tmpdisuv; log++);
                    log--;

                    while(tmpdisuv>=1)
                    {
                        temp = sparse[temp][log];
                        tmpdisuv = tmpdisuv-(1<<log);

                        for(log=0; (1<<log)<=tmpdisuv; log++);
                        log--;
                    }
                    resv = temp;
                }
                if(resu>resv) swap(resu,resv);
                pf("The fleas jump forever between %d and %d.\n", resu,resv);
            }


            /////////////////////////////////

            else
            {
                disuv/=2;
                int res;//cout<<level[u]-level[lcauv]<<" ........ " << lcauv << endl;;
                if(disuv<=level[u]-level[lcauv])
                {
                    int log,temp=u;
                    for(log = 0; (1<<log)<=disuv; log++);
                    log--;
//cout<<u<<" "<<temp<<endl;
                    while(disuv>=1)
                    {
                        temp = sparse[temp][log];//cout<<u<<" "<<temp<<endl;
                        disuv = disuv-(1<<log);
                        for(log=0;(1<<log)<=disuv; log++);
                        log--;
                    }
                    pf("The fleas meet at %d.\n", temp);
                }
                else
                {
                    int log,temp=v;

                    for(log=0; (1<<log)<=disuv; log++);
                    log--;
//cout<<temp<<endl;
                    while(disuv>=1)
                    {
                        temp = sparse[temp][log]; //cout<<v<<" "<<temp<<endl;
                        disuv = disuv - (1<<log);

                        for(log=0; (1<<log)<=disuv; log++);
                        log--;
                    }
                    pf("The fleas meet at %d.\n", temp);
                }
            }
        }
    }
    return 0;
}

/*

14

1 3
1 2
3 7
3 6
2 4
2 5
5 8
8 10
4 9
9 11
11 12
12 13
13 14

*/