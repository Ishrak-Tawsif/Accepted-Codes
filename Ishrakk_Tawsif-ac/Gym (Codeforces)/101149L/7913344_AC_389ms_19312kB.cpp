#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 200005
#define ll long long int
#define mp make_pair
/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/


vector <int> graph[mx];
vector <int> graph2[mx];
//ll vis[mx],q[1001],ans,cnt,cost[1001][1001],
ll dis[4][mx];
int a,b;

void bfs(int s,int type)
{

    queue<int>q;
    q.push(s);
    dis[type][s]=0;

        while(!q.empty())
        {
            int u=q.front(); q.pop();
            int len;
            if(type == 1) len=graph[u].size();
            else len=graph2[u].size();
                for(int i=0; i<len; i++)
                {
                    int v;
                    if(type==1)v=graph[u][i];
                    else v=graph2[u][i];

                        if(dis[type][v]>dis[type][u]+1){
                            //vis[type][v]=1;
                            q.push(v);
                            dis[type][v]=dis[type][u]+1;
                            //path[v].pb(u);
                        }
                }
        }
}

/*ll get_path()
{
    ll temp=a,i=0;
    ll min_ = (ll) dis[temp];//cout<<"min "<<min_<<endl;
        while(temp!=0 && path[temp].size()>i)
        {
            //cout<<path[temp][0]<<" ";
            min_ = min(min_,dis[path[temp][0]]);
            temp=path[temp][0];
            i++;
        }
    //cout<<endl;
    return min_;
}*/

int main()
{
   int n,m,u,v;

        while(scanf("%d %d %d %d", &n, &m, &a, &b) == 4)
        {

            loop(m)
            {
                scanf("%ld %ld", &u, &v);
                graph[u].pb(v);
                graph2[v].pb(u);
            }

            for(int i=0; i<mx; i++){
                dis[1][i]=dis[2][i]=dis[3][i]=INT_MAX;
            }

            bfs(0,1);
            bfs(a,2);
            bfs(b,3);
            ll ans=LONG_LONG_MAX;  //cout<<dis[a]<<" "<<dis[b]<<".."<<endl;

                loop(n+1){
                    //cout<<dis[1][i]<<" "<<dis[2][i]<<" "<<dis[3][i]<<endl;
                    ans=min(ans,dis[1][i]+dis[2][i]+dis[3][i]);
                }

            pf("%lld\n",ans);
        }
   return 0;
}

/*
4 2 1 4
0 1
0 4
*/