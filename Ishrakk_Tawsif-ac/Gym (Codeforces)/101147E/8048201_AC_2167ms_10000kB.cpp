#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100005
#define ll long long int
#define mp make_pair
#define mod 100000007

vector <int> graph[mx];
int dis[mx],vis[mx],fl=0,arr[mx],n;

/*void dfs(int s)
{
    if(!vis[s]){//cout<<s<<"..."<<endl;
    vis[s]=1;
        for(int i=0; i<graph[s].size(); i++)
        {
            int vv=graph[s][i];
            dis[vv]=dis[s]+1;//cout<<dis[vv]<<"///"<<endl;
                if(graph[vv].size() == 0 && dis[vv]%2!=0) {fl=1; break;}
            if(fl==1) break;
            dfs(vv);
            vis[vv]=0;
        }
    }
}*/

int bfs(int s)
{
    set <pair<int,int> > st;
    dis[s]=0;
    vis[s]=1;
    st.insert(make_pair(0,s));

        while(!st.empty())
        {
            pair<int,int> temp= *st.begin(); st.erase(st.begin());
            int ucost=temp.first;
            int u=temp.second;//cout<<u<<"..."<<endl;

            //if(u==n) return dis[n];

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];
                    int vcost=dis[v];

                        if(!vis[v] && vcost>ucost+1)
                        {
                            vis[v]=1;
                            dis[v]=ucost+1;//cout<<"v "<<v<<" "<<dis[v]<<endl;
                            st.insert(make_pair(dis[v],v));
                        }
                }
        }
   //return -1;
}

int main()
{
   freopen("jumping.in", "r",stdin);
   int tc;
   sf(tc);

   while(tc--){

        sf(n);
        loop1(i,n) scanf("%d", &arr[i]);
        for(int i=0; i<=n; i++) graph[i].clear();
            for(int i=1; i<=n; i++)
            {
                int u=i+arr[i];
                int v=i-arr[i]; //cout<<i<<"..."<<endl;
                if(u>0 && u<=n){graph[u].pb(i); /*graph[u].pb(i);*/}
                if(v>0 && v<=n){graph[v].pb(i); /*graph[v].pb(i);*/}

            }//cout<<graph[5].size()<<endl;
                for(int i=1; i<=n; i++){vis[i]=0; dis[i]=INT_MAX;}
                bfs(n);

                for(int i=1; i<=n; i++){ //cout<<i<<"..."<<endl;cout<<dis[n]<<endl;
                    if(dis[i]==INT_MAX) pf("-1\n");
                    else pf("%d\n", dis[i]);
                }
            //}
   }
   return 0;
}