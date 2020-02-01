#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100003
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
//int dir_r_4[]={-1,1,0,0};
//int dir_c_4[]={0,0,-1,1};

double arr[mx],dp[mx],vis[mx];
//int n;
vector <int> divisor[mx];

int main()
{

    for(int i=1; i<mx; i++)
    {
        for(int j=i; j<mx; j+=i) divisor[j].pb(i);
    }

    int tc,day,i;
        sf(tc);

            loop1(tt,tc)
            {
                double pro=1.0;

                scanf("%d", &day);

                //double poww = (double) (log (0.5)/(log((day-1)/day)));

                //double ans = (1.0+sqrt(1.0+(4.0*2.0*poww)))/2.0;

                for(i=1; ; i++)
                {
                    pro *= (double) (day-i)/day;//cout<<pro<<endl;
                    if(pro<=0.5) break;
                }
                //cout<<ans<<endl;
                pf("Case %d: %d\n",tt,i);
            }
    return 0;
}