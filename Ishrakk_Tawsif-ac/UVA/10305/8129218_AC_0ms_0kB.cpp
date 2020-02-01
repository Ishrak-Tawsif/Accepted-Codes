#include<bits/stdc++.h>
using namespace std;

vector <int> graph[103],topsort;
int vis[103],vis2[103];

void dfs(int s)
{
    vis[s]=1;

        for(int i=0; i<graph[s].size(); i++)
            {
                if(!vis[graph[s][i]]) dfs(graph[s][i]);
            }
    //if(!vis2[s]){
        topsort.push_back(s);
        //vis2[s]=1;
    //}
}

int main()
{
    int n,m,u,v;

        while(scanf("%d %d", &n, &m) == 2){
            if(n==0 && m==0) break;

            topsort.clear();
            for(int i=0; i<103; i++) {vis[i]=0; graph[i].clear();vis2[i]=0;}

                for(int i=0; i<m; i++)
                {
                   scanf("%d %d", &u,&v);
                   graph[u].push_back(v);
                }
            for(int i=1; i<=n; i++)
            {
                if(!vis[i]){
                    //vis2[i]=1;
                    dfs(i);
                    //topsort.push_back(i);
                }
            }
            //cout<<topsort.size()<<endl;
            cout<<topsort[topsort.size()-1];
            for(int i=topsort.size()-2; i>=0; i--) cout<<" "<<topsort[i];
            cout<<endl;
        }

    return 0;
}