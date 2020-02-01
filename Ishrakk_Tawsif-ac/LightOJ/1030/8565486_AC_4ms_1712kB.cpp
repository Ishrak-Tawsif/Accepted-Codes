#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1000000005
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
//int dir_r_4[]={-1,1,0,0};
//int dir_c_4[]={0,0,-1,1};

double arr[1001],dp[1003],vis[1003];
int n;


double call(int pos)
{

    if(pos > n) {return 0;}
    if(vis[pos]!=0) return dp[pos];

        vis[pos]=1;

        double ans=0.0,back_to_me=0.0;
        for(int i=1; i<=6; i++)
        {
            int temp=pos+i;

                if(temp>n)
                {
                    back_to_me += (1.0/6.0);//cout<<back_to_me<<"btm"<<endl;
                }
                else
                {
                    ans += call(temp)*(1.0/6.0);
                }
        }
        back_to_me = (1-back_to_me);
        ans = (ans/back_to_me)+arr[pos];//cout<<back_to_me<<" "<<ans<<"..."<<endl;
    return dp[pos]=ans;
}

int main()
{
    int tc;
        sf(tc);

            loop1(tt,tc)
            {
                sf(n);
                loop1(i,n) cin>> arr[i];
                memset(vis,0,sizeof(vis));//printf("%f\n",arr[1]);cout<<arr[1]<<endl;
                //cout<<"Case "<<tt<<": "<<call(1)<<endl;
                double ans=call(1);
                printf("Case %d: %f\n",tt,ans);
            }
    return 0;
}