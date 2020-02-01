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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007

int flen,in,mark[2005],dp[205][80005],track[205][80005],ar[2005];

int knapsack(int i,int len)
{
    if(len<0) return -inf;
    if(i<0) return 0;
    if(dp[i][len] != -1) return dp[i][len];

    int ans=0,ans1=0;
    /*if(len+ar[i] <= flen) ans = knapsack(i+1,len+ar[i])+ar[i];
    ans1 = knapsack(i+1,len);*/

    ans = knapsack(i-1,len-ar[i]) + ar[i];
    ans1 = knapsack(i-1,len);

    track[i][len] = ans>ans1? 1 : 0;

    return dp[i][len] = max(ans,ans1);
}

int solve()
{
    int cnt=0,tot=0;
    for(int i=0; i<=in; i++)
    {
        if(mark[i]) cnt++;
        else
        {
            tot += ar[i];

            if(tot<=flen)
            {
                //tot += ar[i];
                //mark[i] = 2;
                cnt++;
            }
        }
    }
    return cnt;
}

void clear_me()
{
    for(int i=0; i<205; i++)
    {
        for(int j=0; j<80005; j++) dp[i][j] = -1, track[i][j] = 0;
    }
    for(int i=0; i<2005; i++) mark[i] = 0;
}

int main()
{//WRITE("in.txt");
    int tc,temp;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &flen);
        flen *= 100;

        in = 0;

        clear_me();

        while(sf(temp) && temp)
        {
            if(in>200) continue;
            ar[in] = temp;
            in++;
        }
//cout<<in<<".."<<endl;

        in--;
        knapsack(in,flen);

        int tot=flen;
        for(int i=in; i>=0; i--)
        {
            //if(tot+ar[i]>=800005) continue;

            if(track[i][tot])
            {//cout<<i<<" .. "<<endl;
                mark[i] = 1;
                tot -= ar[i];
            }
        }

        pf("%d\n",solve());

        int tota=0;
        for(int i=0; i<=in; i++)
            if(mark[i] == 1)pf("port\n");
            else
            {
                tota += ar[i];
                if(tota<=flen)   pf("starboard\n");
            }

        if(tt!=tc) pf("\n");
    }
    return 0;
}