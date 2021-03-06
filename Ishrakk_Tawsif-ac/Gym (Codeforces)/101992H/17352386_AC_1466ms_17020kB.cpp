#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

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
#define mx                      100005
#define mod                     10

int n,m,u,l,k,res,vis[mx];
//unordered_map <int,unordered_map<int,int> > vis;
vector <pair<int,int > > graph[mx];

void bfs(int sr)
{
    mem(vis,0);
    queue <pair<int,int> > q;
    vis[sr] = 1;
    q.push({sr,0});

    while(!q.empty())
    {
        int now = q.front().first;
        int nowcst = q.front().second;
        q.pop();

        for(int i=0; i<graph[now].size(); i++)
        {
            int v = graph[now][i].first;
            int cst = graph[now][i].second;

            res = max(res,cst);
            if(nowcst+1<k && !vis[v])
            {
                vis[v] = 1;
                q.push({v,nowcst+1});
            }
        }
    }
}

int main()
{
    READ("path.in");

    int tc,a,b,cst;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        for(int i=0; i<mx; i++) graph[i].clear();

        scanf("%d %d %d %d %d", &n,&m,&u,&l,&k);

        for(int i=1; i<=m; i++)
        {
            scanf("%d %d %d", &a,&b,&cst);
            graph[a].pb({b,cst});
            graph[b].pb({a,cst});
        }

        res = 0;
        bfs(u);
        printf("%d\n", res);
    }

    return 0;
}