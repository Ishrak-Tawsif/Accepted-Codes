#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2005
#define ll long long int
#define mp make_pair
#define mod 100000007

int n,vis[mx],x[mx],y[mx],d[mx],top_sort[mx],in;
vector <int> graph[mx];

int dfs(int n)
{
    vis[n]=1;
    for(int i=0; i<graph[n].size(); i++)
        if(!vis[graph[n][i]])
            dfs(graph[n][i]);
    top_sort[++in]=n;//cout<<n<<" ts "<<endl;
}

int bfs(int s)
{
    queue <int> q;
    vis[s]=1;
    q.push(s);

        while(!q.empty())
        {
            int u=q.front(); q.pop();
//cout<<u<<" .. "<<endl;
                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];

                        if(!vis[v])
                        {
                            vis[v]=1;//cout<<v<<endl;
                            q.push(v);
                        }
                }
        }
}

int main()
{
    int tc;
        sf(tc);
            while(tc--)
            {
                sf(n);

                loop(i,mx) graph[i].clear();
                    loop1(i,n)scanf("%d %d %d", &x[i],&y[i],&d[i]);

                        for(int i=1; i<=n; i++)
                        {
                            for(int j=1; j<=n; j++){
                                if(i==j) continue;
                                int temp=(d[i]/2);
                                if((abs(x[j]-x[i])<=temp) && (abs(y[j]-y[i])<=temp))
                                    {graph[i].pb(j);/*cout<<i<<" "<<j<<endl;*/}
                            }
                        }

                int ans=0;
                in=0;

                memset(vis,0,sizeof(vis));
                for(int i=1; i<=n; i++) if(!vis[i])dfs(i);

                memset(vis,0,sizeof(vis));
                for(int i=n; i>=1; i--)
                {//cout<<i<<endl;
                    if(!vis[top_sort[i]])
                    {//cout<<i<<".. "<<endl;
                        ans++;
                        bfs(top_sort[i]);
                    }
                }

                pf("%d\n",ans);
            }
    return 0;
}


/*
1
4
6 7 8
9 10 4
11 5 4
15 9 8
*/