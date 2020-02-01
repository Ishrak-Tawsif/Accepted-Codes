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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

vector <int> graph[150005];
ll cnted=0,cntnod=0;
int vis[150005];

bool bfs(int s)
{
    vis[s] = 1;
    queue <int> q;
    q.push(s);
    cntnod++;

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v = graph[u][i];
                    cnted++;
                        if(!vis[v])
                        {
                            vis[v] = 1;
                            cntnod++;
                            q.push(v);
                        }
                }
        }
        cnted/=2;
        ll temp = (cntnod) * (cntnod-1);
        temp /= (ll)2;//cout<< cnted << " " << temp << endl;
        if(temp == cnted) return true;
        return false;
}

int main()
{
    int n,m,u,v,call=-1,fl=1;

        sf(n); sf(m);


            loop(i,0,m)
            {
                sf(u);
                sf(v);
                //if(fl==0){call=u;fl=1;}
                graph[u].pb(v);
                graph[v].pb(u);
            }

            bool ans;

            for(int i=1; i<=n; i++)
            {
                if(!vis[i])
                {
                    cnted=cntnod=0;

                    if(!bfs(i)) {fl=0; break;}
                }
            }

            (fl==1)? pf("YES\n") : pf("NO\n");
    return 0;
}