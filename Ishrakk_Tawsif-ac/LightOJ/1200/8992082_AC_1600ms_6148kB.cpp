#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1003
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};



int wei[103],cost[103],q[103],dp[103][10005],WW,nn;


int call(int pos,int w)
{
    if(pos > nn) return 0;/*(((int) w/wei[pos])*cost[pos]);*/
    if(dp[pos][w] != -1) return dp[pos][w];

        int ans1=0,ans2=0,ans3=0;


            if(w+wei[pos]<=WW) ans1 = call(pos+1,w+wei[pos]) + cost[pos];
            if(w+wei[pos]<=WW) ans2 = call(pos,w+wei[pos]) + cost[pos];

            ans3 = call(pos+1,w);


    return dp[pos][w]=max(ans1,max(ans2,ans3));
}

int main()
{
    int tc,ww;

        sf(tc);

            loop1(tt,tc)
            {
                scanf("%d %d", &nn,&ww);
                WW=ww;

                    loop1(i,nn) {scanf("%d %d %d",&cost[i],&q[i],&wei[i]); WW -= (wei[i]*q[i]);}

                    if(WW>=0)
                    {
                        memset(dp,-1,sizeof(dp));
                        pf("Case %d: %d\n",tt,call(1,0));
                    }
                    else
                    {
                        pf("Case %d: Impossible\n",tt);
                    }
            }
    return 0;
}