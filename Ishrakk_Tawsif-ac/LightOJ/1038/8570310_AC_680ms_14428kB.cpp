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
int n;
vector <int> divisor[mx];

double call(int num)
{

    if(num == 1) {return 0.0;}
    if(vis[num]!=0) return dp[num];

        vis[num]=1;

        int len=divisor[num].size();
        double ans=0.0,back_to_me=0.0,possibilty=(1/(len*1.0));
      
        for(int i=0; i<len; i++)
        {
            int temp= (num/divisor[num][i]);
            if(temp == num)
            {
                back_to_me += possibilty;
            }
            else ans += call(temp) * possibilty;
        }
        back_to_me=(1.0-back_to_me);
        ans = ((ans+1.0) / back_to_me);
    return dp[num]=ans;
}

int main()
{
    
    for(int i=1; i<mx; i++)
    {
        for(int j=i; j<mx; j+=i) divisor[j].pb(i);
    }

    int tc;
        sf(tc);

            loop1(tt,tc)
            {
                sf(n);
                
                memset(vis,0,sizeof(vis));
                double ans=call(n);
                printf("Case %d: %f\n",tt,ans);
            }

    return 0;
}