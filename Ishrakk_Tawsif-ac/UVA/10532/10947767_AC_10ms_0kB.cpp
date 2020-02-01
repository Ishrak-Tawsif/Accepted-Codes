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
#define inf                     2e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int track[53],in,cur,n,cnt[53];
ll dp[53][53];

ll call(int i,int j)
{//cout<<i<<" " << j << endl;
    if(j == cur) return 1;
    if(j > cur) return 0;
    if(i>=n) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    ll ans = 0;

    for(int k=0; k<=cnt[i]; k++)
    {
        if(j+k<=cur)ans += call(i+1, j+k);
    }

    //track[ar[i]] = 0;

    return dp[i][j] = ans;
}

int main()
{//WRITE("in.txt");
    int m,temp,tt=0;

    while(~scanf("%d %d", &n,&m))
    {
        if(!n && !m) break;
        mem(track,0);
        mem(cnt,0);

        in = -1;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &temp);
            //ar[i] = temp;
            track[temp]++;
        }

        for(int i=0; i<=50; i++) if(track[i] != 0) cnt[++in] = track[i];

        casepf(++tt);

        while(m--)
        {
            sf(cur);
            mem(dp,-1);

            ll res = 0;
            res = call(0,0);
        //for(int i=0; i<=in; i++) {/*cout<<call(i,0)<<".."<<endl;*/res += call(i,0);}

            pf("%lld\n", res);
        }
    }
    return 0;
}