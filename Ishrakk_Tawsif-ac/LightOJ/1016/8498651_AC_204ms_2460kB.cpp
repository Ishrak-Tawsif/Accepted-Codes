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

//int row,col,r,c,cost[21][21],dis[21][21],vis[21][21],dp[21][1<<21],len;
string grid[21];
vector <pair<int,int> >vv,cc;

int dir_r[]={-1,-1,-1,0,0,1,1,1};
int dir_c[]={-1,0,1,-1,1,-1,0,1};

/*int time_needed()
{
    double end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used<<endl;
}*/

struct order
{
    int s,e;

        bool operator < (const order &x) const
        {
            //if(s == x.s) return e<x.e;
            //else
                return e<x.e;
        }
};

vector <order> ord;

int main()
{
    int n,w,tc;

    sf(tc);

    loop1(tt,tc)
    {

        sf(n); sf(w);

            order get;
            ord.clear();

                for(int i=0; i<n; i++)
                {
                    sf(get.s);
                    sf(get.e);
                    ord.pb(get);
                }
                sort(ord.begin(),ord.end());

                int now=ord[0].e+w,cnt=1;

                for(int i=1; i<n; i++)
                {
                    if(ord[i].e>now)
                    {
                        cnt++;
                        now=ord[i].e+w;
                    }
                }
                pf("Case %d: %d\n",tt,cnt);//system("pause");
    }
    return 0;
}