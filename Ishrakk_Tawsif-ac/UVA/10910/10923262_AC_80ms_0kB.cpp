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
#define inf                     1e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int sub,totnum,minnum;
ll dp[73][73];

ll call(int i,int tot) ///sub num
{//cout<<i<<" "<<tot<<endl;
    if(i>sub) return 0;
    if(i == sub)
    {
        if(tot == totnum) return 1;
        else return 0;
    }
    if(dp[i][tot] != -1) return dp[i][tot];

    ll ans = 0,ans2 ;

    for(int j=minnum; j<=minnum+(totnum-(sub*minnum)); j++)
    {//cout<<tot+j<<"..."<<endl;
        if(tot+j<=totnum) ans += call(i+1,tot+j);
    }
//out(ans);
    return dp[i][tot] = ans;
}

int main()
{//WRITE("in.txt");
    ll temp;
    int tc;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
       scanf("%d %d %d", &sub, &totnum, &minnum);
       //cout<<minnum+(totnum-(sub*minnum))<<endl;system("pause");
       mem(dp,-1);
       ll res = call(0,0);
       pf("%lld\n", res);
    }

    return 0;
}