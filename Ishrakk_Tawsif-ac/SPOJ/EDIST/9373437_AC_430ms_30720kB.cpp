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


string str1,str2;
int dp[2005][2005];

int call(int i,int j)
{
    if(i<0) return max(0,j);
    if(j<0) return max(0,i);
    if(dp[i][j] != -1) return dp[i][j];

        int ans=0;
        if(str1[i-1] == str2[j-1]) ans=call(i-1,j-1);
        else ans = 1+min(call(i-1,j),min(call(i,j-1),call(i-1,j-1)));
        //cout<<i<<" " <<j<<" "<<ans<<endl;
    return dp[i][j] = ans;
}

int main()
{
    int tc;

        sf(tc);

            loop(tt,1,tc+1)
            {
                cin>> str1>> str2;
                int len1 = str1.length(),len2=str2.length();

                if(len1 == 0) pf("%d\n", len2);
                else if(len2 == 0) pf("%d\n",len1);
                else{
                    mem(dp,-1);
                    pf("%d\n", call(len1,len2));
                }
            }

    return 0;
}