//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*#define sf(nn)                  scanf ("%d", &nn)
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
*/

string str;
int dp[5005][5005];

int call(int i,int j)
{
   if(i >= j) return 0;
   if(dp[i][j] != -1) return dp[i][j];
//cout<<i<<" " <<j<<endl;
        int ans=0;
        if(str[i]  == str[j]) ans=call(i+1,j-1);
        else ans=min(call(i,j-1)+1,call(i+1,j)+1);
   return dp[i][j] = ans;
}

int main()
{
    int n;
        //sf(n);
        for(int i=0; i<5005; i++) for(int j=0; j<5005; j++) dp[i][j]=-1;
        cin>>n >> str;
            //mem(dp,-1);
            //pf("%d\n", call(0,n-1));
            cout<<call(0,n-1)<<endl;

    return 0;
}