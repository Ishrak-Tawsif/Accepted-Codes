#include<bits/stdc++.h>
using namespace std;

#define mx 50003

vector <int> graph[mx];
//bitset <mx> vis;
int dis[mx],vis[mx],vis2[mx],max_;


int dfs(int s)
{
    vis[s]=vis2[s]=1;

        for(int i=0; i<graph[s].size(); i++)
        {
            int v=graph[s][i];
            if(!vis2[v]) {
                dis[v]=dis[s]+1;
                max_=max(max_,dis[v]);
                dfs(v);
            }
        }
    vis2[s]=0;
}

///getting timelimit using bfs because of initiate vis2 to 0 everytime
/*int bfs(int s)
{
    memset(vis2,0,sizeof(vis2));

    queue <int> q;
    q.push(s);
    dis[s]=0;
    vis2[s]=1;
    int max_=0;

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];
                        if(!vis2[v])
                        {
                            vis[v]=vis2[v]=1;
                            dis[v]=dis[u]+1;//cout<<".."<<v<<endl;
                            max_=max(max_,dis[v]);
                            q.push(v);
                        }
                }
        }
    return max_;
}*/

int main()
{
    int tc,n,u,v;
        scanf("%d", &tc);

            for(int tt=1; tt<=tc; tt++)
            {
                for(int i=0; i<mx; i++) graph[i].clear();

                scanf("%d", &n);
                    for(int i=0; i<n; i++)
                    {
                        scanf("%d %d", &u,&v);
                        graph[u].push_back(v);
                    }
                int ans=INT_MIN,aa;

                    memset(vis,0,sizeof(vis));
                    for(int i=1; i<=n; i++)
                    {

                        if(!vis[i]){

                            dis[i]=0;
                            max_=INT_MIN;

                            int temp=dfs(i);//cout<<i<<" "<<ans<<" "<<max_<<endl;
                            //for(int i=1;i<=n; i++) cout<<vis2[i]<<" "; cout<<endl;
                            if(max_>ans)
                            {//cout<<i<<" "<<max_<<endl;
                                ans=max_;
                                aa=i;
                            }
                        }
                    }
                    printf("Case %d: %d\n",tt,aa);
            }

    return 0;
}