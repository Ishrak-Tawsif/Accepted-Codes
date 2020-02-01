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
#define ll                      unsigned long long int
#define mx                      5005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int dir_r[] = {-1,0,1,0};
int dir_c[] = {0,-1,0,1};
int vis[105][105];

string s[105];
int fl,x,y,n,rrr,ccc;
ll dp[105][105];

ll call(int r,int c)
{//cout<<r<<" " << c << endl;//system("pause");

    if(r<0 || r>=n || c<0 || c>=n) return 0;
    //if(vis[r][c]) return (dp[r][c])%mod;
    //vis[r][c]=1;
    if(r == 0)
    {//cout<<r<<" " << c << endl;
        if(s[r][c] != 'B') return 1;
        //else return 0;
    }
    if(dp[r][c] != -1) return dp[r][c]%mod;

        ll ans=0;

            int tr = r-1;
            int tc = c-1;
            if(s[tr][tc] == 'B')
            {
                if(tr-1>=0 && tc-1>=0)
                {
                       if(s[tr-1][tc-1] != 'B') ans = ((ans%mod) + (call(tr-1,tc-1))%mod)%mod;
                }
                /*else
                {
                    if(tr+1>n)rrr=(tr+1)-n;
                    if(tc+1>n)ccc=(tc+1)-n;
                    ans = ((ans%mod)+(call(rrr,ccc)%mod))%mod;
                }*/
            }
            else
            {
                ans = ((ans%mod) + (call(tr,tc))%mod)%mod;
            }

            ans = ans%mod;

            tr = r-1;
            tc = c+1;

            if(s[tr][tc] == 'B')
            {
                if(tr-1>=0 && tc+1<n)
                {
                       if(s[tr-1][tc+1] != 'B') ans = ((ans%mod) + (call(tr-1,tc+1))%mod)%mod;
                }
                /*else
                {
                    if(tr-1<0)rrr=0;
                    if(tc+1>n)ccc=(tc+1)-n;
                    ans = ((ans%mod)+(call(rrr,ccc)%mod))%mod;
                }*/
            }
            else
            {
                ans = ((ans%mod) + (call(tr,tc))%mod)%mod;
            }

    return dp[r][c] = ans%mod;
}

int main()
{
    int tc;

        sf(tc);

            loop(tt,1,tc+1)
            {
                sf(n);
                fl=0;
                    loop(i,0,n)
                    {
                        cin>> s[i];
                        if(fl==1) continue;
                        loop(j,0,n)

                            {
                                if(s[i][j] == 'W')
                                {
                                    x = i;
                                    y = j;
                                    fl=1;
                                    break;
                                }
                            }
                    }//cout<<x<<" "<<y<<endl;
                    memset(dp,-1,sizeof(dp));
                    pf("Case %d: %lld\n", tt,call(x,y));
            }

    return 0;
}