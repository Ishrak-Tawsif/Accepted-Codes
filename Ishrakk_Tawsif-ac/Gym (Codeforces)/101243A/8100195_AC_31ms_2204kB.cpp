#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007


/*vector <int> graph[mx];
int vis[mx],dis[mx],level[mx],fl;

int bfs(int s)
{
    queue <int> q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;

        while(!q.empty())
        {
            int u=q.front(); q.pop();

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];
                    fl=1;
                        if(!vis[v])
                        {
                            dis[v]=dis[u]+1;
                            level[dis[v]]++;
                            vis[v]=1;
                            q.push(v);
                        }
                }
        }
}*/

int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
        while(cin>>n>>k)
        {
            int ans;
            if(n<k) {cout<<2<<endl; continue;}
                n*=2;
                    if(n%k == 0) ans=n/k;
                    else ans=(n/k)+1;
                    
                    cout<<ans<<endl;
        }
    return 0;
}