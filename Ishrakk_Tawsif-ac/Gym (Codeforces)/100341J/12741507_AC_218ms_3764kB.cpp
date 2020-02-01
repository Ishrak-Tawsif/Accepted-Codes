#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      557
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,m;
ll edge[305][305],cost[305][305];

void warshall()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                if(cost[j][k]>cost[j][i]+cost[i][k])
                {
                    cost[j][k] = cost[j][i] + cost[i][k];
                    edge[j][k] = edge[j][i] + edge[i][k];
                }
                else if(cost[j][k] == cost[j][i]+cost[i][k])
                {
                    if(edge[j][k]>edge[j][i]+edge[i][k])
                    {
                        edge[j][k] = edge[j][i] + edge[i][k];
                    }
                }
            }
        }
    }
}

int main()
{

    READ("trip.in");
    WRITE("trip.out");

    for(int i=0; i<305; i++)
    {
        for(int j=0; j<305; j++)
        {
            if(i == j) cost[i][j] = 0;
            else cost[i][j] = 2e18;
        }
    }

    scanf("%d %d", &n,&m);

    int u,v,cs;


    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &u,&v,&cs);

        if(cost[u][v] == 2e18)
        {
            cost[u][v] = cs;
            cost[v][u] = cs;
            edge[u][v] = edge[v][u] = 1;
        }
        else
        {
            if(cost[u][v]>cs) cost[u][v] = cs,cost[v][u] = cs;
        }
    }

    warshall();

    double tot = 0.0;
    int cnt = 0;

    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            //cout<<diss[i][j]<<" "<<edge[i][j]<<endl;
            tot += (edge[i][j] * 1.0);
            cnt ++;
        }
    }

    pf("%.17f\n", (tot/(cnt * 1.0)));

    return 0;
}