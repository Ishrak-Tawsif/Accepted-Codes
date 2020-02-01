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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};


vector <int> graph[205];
int dist[205][205],ind,n,m;
map<string,int>mpp;

void floyd_warshall_minmax()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                dist[j][k] = (max(dist[j][k],min(dist[j][i],dist[i][k])));
                dist[k][j] = dist[j][k];
            }
        }
    }
}


int main()
{
    string u,v;
    int c,tt=0;

    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n==0 && m==0) break;

            mpp.clear();
            for(int i=0; i<205; i++){
                for(int j=0; j<205; j++) dist[i][j] = -1;
                dist[i][i]=0;
            }

            ind=0;
            loop(i,0,m)
            {
                cin>>u>> v>> c;
                if(mpp[u] == 0) mpp[u]=++ind;
                if(mpp[v] == 0) mpp[v]=++ind;
                dist[mpp[u]][mpp[v]] = c;
                dist[mpp[v]][mpp[u]] = c;
            }

            floyd_warshall_minmax();

            string source,destination;
            cin>> source>> destination;

            int ind_src = mpp[source];
            int ind_des = mpp[destination];

            pf("Scenario #%d\n%d tons\n\n", ++tt,dist[ind_src][ind_des]);
    }
    return 0;
}