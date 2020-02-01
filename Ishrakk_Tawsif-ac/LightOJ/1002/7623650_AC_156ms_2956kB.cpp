#include<bits/stdc++.h>
using namespace std;

vector <int> vv[501];
//vector <int> cost[501];
int c[501],vis[501],cost[501][501],m_dis[501];

void bfs(int ss){

    for(int i=0; i<501; i++){
         c[i]=INT_MAX; vis[i]=0; m_dis[i]=INT_MAX;
    }

        set <pair<int,int> >s;
        s.insert(make_pair(0,ss));
        //vis[ss]=1;
        c[ss]=0;
        m_dis[ss]=0;

            while(!s.empty()){
                pair <int,int>p =*s.begin(); s.erase(s.begin());
                 int u= p.second;//cout<<vis[u]<<" " <<u <<endl;
                 //int u_cost=p.second;
                    if(vis[u]) continue;
                    for(int i=0; i<vv[u].size(); i++){
                        int v=vv[u][i];
                        int v_cost=max(m_dis[u],cost[u][v]);

                            if(m_dis[v]>v_cost){

                                m_dis[v]=v_cost;
                                s.insert(make_pair(m_dis[v],v));

                            }
                    }
                    vis[u]=1;
            }
}

int main(){

    int tc,n,e,cs,sr;
        scanf("%d", &tc);
            for(int tt=1; tt<=tc; tt++){

                for(int i=0; i<501; i++) vv[i].clear();
                for(int i=0; i<501; i++) {
                      for(int j=0; j<501; j++)  cost[i][j]=INT_MAX;
                }

                scanf("%d %d", &n, &e);

                    int u,v;
                    for(int i=0; i<e; i++){
                        scanf("%d %d %d", &u, &v, &cs);
                        vv[u].push_back(v);
                        vv[v].push_back(u);
                        if(cost[u][v]>cs){
                            cost[u][v]=cs;
                            cost[v][u]=cs;
                        }
                    }

                    scanf("%d", &sr);
                    bfs(sr);
                    printf("Case %d:\n", tt);
                    for(int i=0; i<n; i++){
                        if(m_dis[i]!=INT_MAX)printf("%d\n", m_dis[i]);
                        else printf("Impossible\n");
                    }
            }
return 0;
}