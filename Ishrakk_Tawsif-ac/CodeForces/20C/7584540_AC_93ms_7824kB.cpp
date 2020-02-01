#include<bits/stdc++.h>
using namespace std;

#define mx 100005

vector <pair<int,int> > v[mx];
int dis[mx],vis[mx],path[mx];
int node,edge,cs,u,vv;

int dijktra(int ss){
    for(int i=0; i<mx; i++){dis[i]=INT_MAX; vis[i]=0;}
        set <pair<int,int> >s;
        dis[ss]=0;
        path[ss]=0;
        s.insert(make_pair(0,ss));

            while(!s.empty()){
                pair <int,int> p = *s.begin();
                s.erase(s.begin());
                int u=p.second;
                if(vis[u])continue;
                int u_cost=p.first;
                    for(int i=0; i<v[u].size();i++){
                        int vv=v[u][i].first;
                        int vv_cost=v[u][i].second;
                            if(dis[vv]>vv_cost+u_cost && !vis[vv]){
                                dis[vv]=vv_cost+u_cost;
                                s.insert(make_pair(dis[vv],vv));
                                path[vv]=u;
                            }
                    }
                vis[u]=1;
            }
}

void path_printing_(){
    printf("%d %d", node,path[node]);
    int i=node;
    while(1) {
        printf(" %d", path[path[i]]);
        if(path[path[i]] == 1) break;
        else i=path[i];
    }
}

void path_printing(int nd){
    if(path[nd] == 0) return;
         path_printing(path[nd]);

            if(path[nd]==1)printf("%d", path[nd]);
            else printf(" %d", path[nd]);
}

int main(){

        scanf("%d %d", &node, &edge);
            for(int i=0; i<edge; i++){
                scanf("%d %d %d", &u, &vv, &cs);
                v[u].push_back(make_pair(vv,cs));
                v[vv].push_back(make_pair(u,cs));
            }

            dijktra(1);

            if(dis[node]==INT_MAX)printf("-1\n");
            else{
                    path_printing(node);
                    printf(" %d", node);
            }
    return 0;
}