#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define mx                      10000007
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

string str1,str2;
int dp[103][103],len1,len2;

int call(int i,int j)
{
    if(i>=len1 || j>=len2) return 0;
    if(dp[i][j] != -1) return dp[i][j];

        int ans1=0,ans2=0;

            if(str1[i] == str2[j]) ans1=call(i+1,j+1)+1;
            else ans1 = max(call(i+1,j),call(i,j+1));

    return dp[i][j]=ans1;
}


int main()
{
    int tt=0;
    while(getline(cin,str1))
    {
        if(str1[0] == '#') break;
        getline(cin,str2);
        tt++;

        len1=str1.length(),len2=str2.length();
        mem(dp,-1);
        pf("Case #%d: you can visit at most %d cities.\n",tt,call(0,0));
    }
    return 0;
}