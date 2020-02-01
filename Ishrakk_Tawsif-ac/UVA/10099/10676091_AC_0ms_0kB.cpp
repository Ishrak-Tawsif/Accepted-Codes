#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int dist[103][103],n;

void floydwarshallminmax()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                dist[j][k] = max(dist[j][k],min(dist[j][i],dist[i][k]));
                dist[k][j] = dist[j][k];
            }
        }
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int tc,u,v,cap,r,tt=0;

    while(scanf("%d %d", &n,&r) && n && r)
    {
        mem(dist,0);
        loop(i,0,r)
        {
            scanf("%d %d %d", &u,&v,&cap);
            dist[u][v] = cap;
            dist[v][u] = cap;
        }

        floydwarshallminmax();
        int s,d,tr;
        scanf("%d %d %d", &s,&d,&tr);
        dist[s][d] --; ///one minus because mr g is also a passenger.
        pf("Scenario #%d\nMinimum Number of Trips = %d\n\n",++tt,(tr/dist[s][d])+(tr%dist[s][d]!=0));
    }

    return 0;
}