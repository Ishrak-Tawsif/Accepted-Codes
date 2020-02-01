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


int main()
{
    ll k,n,m,mars,others,ans;
    string str;

        while(scanf("%lld %lld %lld", &k,&n,&m) == 3)
        {
            ans=mars=others=0;

                for(int i=0; i<k; i++)
                {
                    cin>> str;

                        if(str == "Mars") mars++;
                        else others++;
                }

                if(m>others) {ans += (m-others); others=0;}
                else others -= m;
                mars+=others;
                if(mars>=n) ans=ans;
                else ans += (n-mars);

                    pf("%lld\n", ans);
        }
    return 0;
}