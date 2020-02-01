#include<bits/stdc++.h>
using namespace std;

#define mp make_pair

vector <pair<int,int> > vv[5001];
int dis[2][5001];
//bool vis[2][5001];


void bfs(int ss,int n){

    for(int i=0; i<5001; i++){
         /*vis[0][i]=0; vis[1][i]=0;*/ dis[0][i]=INT_MAX; dis[1][i]=INT_MAX;//cout<<i<<"\n";
    }
//cout<<"drfg";
        set <pair <pair <int,int>, int> >s;
        s.insert(mp(mp(1,0),ss));
        dis[1][ss]=0;
            while(!s.empty()){

                pair <pair <int,int>, int >p =*s.begin(); s.erase(s.begin());

                 int u= p.second;
                 int u_cost=p.first.second;
                 int type=p.first.first;
                    //cout<< "u = " << u << " u_cost = " << u_cost << " type = " << type <<endl;
                    //if(vis[type][u]) continue;
                      if(u==n && type==1) break;
                        for(int i=0; i<vv[u].size(); i++){
                            int v=vv[u][i].first;
                            int v_cost=vv[u][i].second+dis[type][u];

                                if(v_cost<dis[0][v]){
                                    dis[1][v]=dis[0][v];
                                    s.insert(mp(mp(1,dis[1][v]),v));
                                    dis[0][v]=v_cost;
                                    s.insert(mp(mp(0,dis[0][v]),v));
                                }
                                else if(v_cost>dis[0][v] && v_cost<dis[1][v]){
                                    dis[1][v]=v_cost;
                                    s.insert(mp(mp(1,dis[1][v]),v));
                                }
                        }

                    //vis[type][u]=1;
            }
}

int main(){

    int tc,n,e,cs;
        scanf("%d", &tc);
            for(int tt=1; tt<=tc; tt++){

                for(int i=0; i<501; i++) vv[i].clear();
                /*for(int i=0; i<501; i++) {
                      for(int j=0; j<501; j++)  cost[i][j]=INT_MAX;
                }*/

                scanf("%d %d", &n, &e);

                    int u,v;
                    for(int i=0; i<e; i++){
                        scanf("%d %d %d", &u, &v, &cs);
                        vv[u].push_back(mp(v,cs));
                        vv[v].push_back(mp(u,cs));
                        /*if(cost[u][v]>cs){
                            cost[u][v]=cs;
                            cost[v][u]=cs;
                        }*/
                    }

                    //scanf("%d", &sr);
                    bfs(1,n);
                    printf("Case %d: ", tt); printf("%d\n", dis[1][n]);
                    //for(int i=0; i<n; i++){
                        //if(m_dis[i]!=INT_MAX)printf("%d\n", m_dis[i]);
                        //else printf("Impossible\n");
                    //}
            }
return 0;
}