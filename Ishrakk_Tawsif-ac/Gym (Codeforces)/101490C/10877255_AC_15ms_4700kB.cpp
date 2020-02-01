#include<bits/stdc++.h>
using namespace std;

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
#define intinf                  7e18
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

vector <int> graph[200005];
int total[200005],cnt[200005],vis[200005];

int bfs(int sr,int home)
{
    vis[sr] = 1;
    queue <int> q;
    q.push(sr);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

                if(u == home) return 1;

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v = graph[u][i];

                    cnt[v]++;

                    int half = (total[v]%2 == 0)? total[v]/2 : ((total[v]/2)+1);

                    if(cnt[v] == half && !vis[v])
                    {
                        q.push(v);
                    }
                }
        }
    return 0;
}

int main()
{
    int node,edge,home,first,u,v;

    scanf("%d %d %d %d", &node,&edge,&home,&first);

    loop(i,0,edge)
    {
        scanf("%d %d", &u,&v);
        graph[u].pb(v);
        graph[v].pb(u);
        total[u] ++;
        total[v] ++;
    }

    (bfs(first,home)==1)? pf("leave\n") : pf("stay\n");

    return 0;
}