#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1000005

vector <int> graph[mx];
vector <int> topsort;
int vis[mx],n,domino;

void dfs(int s)
{
    vis[s]=1;
        loop(graph[s].size())
        {
            int ss=graph[s][i];
            if(!vis[ss]) dfs(ss);
        }
    topsort.pb(s);
}

int componentcount()
{
    memset(vis,0,sizeof(vis));//cout<<<<endl;
    for(int i=1; i<=domino; i++) if(!vis[i]){dfs(i);}
    int cnt=0;
    memset(vis,0,sizeof(vis));
        for(int i=topsort.size()-1; i>=0; i--)
        {
            if(!vis[topsort[i]])
                {
                    cnt++;//cout<<topsort[i]<<endl;
                    dfs(topsort[i]);
                }
        }
    return cnt;
}

int main()
{
    int u,v,node;
        while(sf(n) == 1)
        {
            while(n--){
                sf(domino);
                sf(node); //cout << domino << " " << node << endl;
                    loop(node){
                        sf(u);
                        sf(v);//cout << node << " " << u << " " << v << endl;
                        graph[u].pb(v);
                    }
                    pf("%d\n",componentcount());
                    for(int i=1; i<=domino; i++) graph[i].clear();
                    topsort.clear();
            }
        }
    return 0;
}