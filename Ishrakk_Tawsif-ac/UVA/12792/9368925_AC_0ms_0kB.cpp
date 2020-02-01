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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int dir_r[] = {0, 0, 1, -1};
int dir_c[] = {1, -1, 0, 0};

int arr[53][53],dp[53][53][53],n,m,vis[51][51][11],vis2[51][51];



/*int call(int i,int j,int cap)
{
    if(vis[i][j][cap]) return dp[i][j][cap];
    if(i<=0 || j<=0) return 0;//cout<<i<<" " << j <<endl;
    if(i>n || j>n) return 0;
    if(dp[i][j][cap] != -1) return dp[i][j][cap];
//cout<<i<<" " <<j<<" "<<cap<<" " << vis[i][j][cap]<<endl;
    int ans=0,ans2=0;
    vis[i][j][cap]=1;
    if(!vis2[i][j])
    {
    vis2[i][j] = 1;
        for(int k=0; k<4; k++)
        {
            int tr = i+dir_r[k];
            int tc = j+dir_c[k];
            if(vis2[tr][tc]) continue;
            vis2[tr][tc]=1;
            if(cap-1>=0) ans = max(ans,max(call(tr,tc,cap-1)+arr[i][j],call(tr,tc,cap)));
            else ans = max(ans,call(tc,tc,cap));

        }//cout<<ans2<< " "<<ans<<" .. \n";

    }vis2[i][j]=0;
    return dp[i][j][cap] = ans;
}*/

int main()
{
    ll n;

        while(cin>> n)
        {
            ll nn=(n/2)+1;
            ll ans = 0;

                while(1)
                {
                    if(nn%2 == 0)
                    {
                        ans++;
                        nn /= 2;
                    }
                    else if(nn%2 == 1)
                    {
                        ans++;
                        nn = (nn+1)/2 + (n/2);
                    }
                    if(nn == 1) break;
                }
                
            cout<<ans+1<<endl;
        }
    return 0;
}