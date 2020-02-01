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

string str;
int ar[10005],dp[10005][103];
int n,k;

int call(int i,int Mod)
{
    if(i == n)
    {//cout<<Mod<<endl;
        if(!Mod){return 1;}
        return 0;
    }
    if(dp[i][Mod] != -1) return dp[i][Mod];

    int ans = call(i+1,(Mod+ar[i])%k);
    ans |= call(i+1,(((Mod-ar[i])%k)+k)%k);

    return dp[i][Mod] = ans;
}

int main()
{//WRITE("in.txt");
    int tc;
    sf(tc);

    while(tc--)
    {
        scanf("%d %d", &n, &k);
        mem(dp,-1);
        for(int i=0; i<n; i++) sf(ar[i]);
        if(call(1,ar[0]%k))pf("Divisible\n");
        else pf("Not divisible\n");
    }
   return 0;
}