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
#define intinf                  1e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

string str,ans[1003][1003];
int ar[10005];
ll dp[205],max_ = -1,lim=INT_MAX;
int n,k;

//ST dp[1005][1005];

ll call(int i)
{//cout<<i<<endl;
    if(i>=str.length()) return 0;
    if(dp[i] != -1) return dp[i];

    ll ans = 0;
    for(int j=i; j<str.length(); j++)
    {
        ans = (ans*10) + (str[j]-'0');
        if(ans>lim) break;//cout<<j<<endl;
        ll temp = ans + call(j+1);
        max_ = max(max_,temp);
    }
    return dp[i] = max_;
}



int main()
{//WRITE("in.txt");
    //string str;
    int tc;
    sf(tc);
    while(tc--)
    {
        cin>> str;
        mem(dp,-1);
        max_=-1;
        pf("%lld\n",call(0));
    }

   return 0;
}