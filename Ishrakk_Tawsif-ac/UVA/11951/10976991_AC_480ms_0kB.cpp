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
#define inf                     1e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int ar[105][105],n,m,k,sum[105][105];

ll dosum()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            sum[i][j] += sum[i-1][j];
            sum[i][j] += sum[i][j-1];
            sum[i][j] -= sum[i-1][j-1];
        }
    }
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout << " " << sum[i][j];
        }pf("\n");
    }*/
}

pair <int,int> call()
{
    pair <int,int> ans;
    ans.first = 0;
    ans.second = 0;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                for(int tempi = i; tempi<=n; tempi++)
                {
                    for(int tempj=j; tempj<=m; tempj++)
                    {
                        int cost = sum[tempi][tempj];
                        cost -= sum[i-1][tempj];
                        cost -= sum[tempi][j-1];
                        cost += sum[i-1][j-1];

                        int curarea = (abs(i-tempi)+1) * (abs(j-tempj)+1);
//cout<<curarea<<endl;
                        if(cost<=k)
                        {
                            if(curarea>ans.first)
                            {
                                ans.first = curarea;
                                ans.second = cost;
                            }
                            else if(curarea == ans.first)
                            {
                                ans.second = min(cost,ans.second);
                            }
                        }
                    }
                }
            }
        }
        return ans;
}

int main()
{//WRITE("in.txt");

    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        mem(sum,0);
        scanf("%d %d %d", &n,&m,&k);
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", &sum[i][j]);

        dosum();
        pair<int,int> res = call();

        pf("Case #%d: %d %d\n",tt,res.first,res.second);
    }

    return 0;
}