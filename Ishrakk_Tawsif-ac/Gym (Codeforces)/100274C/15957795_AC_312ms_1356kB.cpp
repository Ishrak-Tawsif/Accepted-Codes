#include <bits/stdc++.h>
using namespace std;

int n,m,vis[10005],cycle,cnt,fl,degree[10005],tot;
vector <int> graph[10005],topsort;

void dfs(int cur)
{
    vis[cur] = 1;

    if(cycle) return;

    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];

        if(!vis[v])
        {
            dfs(v);
        }
        else if(vis[v] == 2)
        {
            //cycle = 1;
            //return;
        }
        else cycle = 1;
    }
    vis[cur] = 2;
    topsort.push_back(cur);
}

int main()
{
    int tc;

    scanf("%d\n", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        for(int i=0; i<10005; i++) graph[i].clear();
        memset(vis,0,sizeof(vis));
        memset(degree,0,sizeof(degree));
        cnt=0;

        scanf("%d %d", &n,&m);

        int u,v;
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].push_back(v);

            degree[v] ++;
        }

    cycle = 0;

    for(int i=1; i<=n; i++) if(!vis[i])dfs(i);
//cout<<cycle<<endl;
        if(cycle) printf("recheck hints\n");
        else
        {
            fl  = 1;
            tot = 0;

            queue <int> q;

            for(int i=1; i<=n; i++) if(!degree[i]) q.push(i);

            while(!q.empty())
            {
                if(q.size() > 1)
                {
                    fl = 0;
                     break;
                }

                int curnode = q.front(); q.pop();

                for(int i=0; i<graph[curnode].size(); i++)
                {
                    int curv = graph[curnode][i];
                    degree[curv] --;
                }
                for(int i=0; i<graph[curnode].size(); i++)
                {
                    int curv = graph[curnode][i];
                    if(!degree[curv]) q.push(curv);
                }
            }

            if(!fl) printf("missing hints\n");
            else
            {
                for(int i=topsort.size()-1; i>=0; i--)
                {
                    if(i == topsort.size()-1) printf("%d",topsort[i]);
                    else printf(" %d", topsort[i]);
                }
                printf("\n");
            }
        }
        topsort.clear();
    }
    return 0;
}

/*
8
8 7
3 1
2 1
5 2
7 2
6 5
4 6
8 7
*/

/*

8
8 8
3 1
2 1
5 2
7 2
6 5
4 6
8 7
7 8
*/