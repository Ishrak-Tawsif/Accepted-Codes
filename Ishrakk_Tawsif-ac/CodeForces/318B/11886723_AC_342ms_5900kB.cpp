#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

int main()
{

    string str;
    string hv = "heavy",mt = "metal";
    while(cin>>str)
    {
        ll len = str.size(),ans=0,res=0;

        for(int i=4; i<len; i++)
        {
                if(str[i] == 'l')
                {
                    if(str[i-4] == 'm' && str[i-3] == 'e' && str[i-2] == 't' && str[i-1] == 'a')
                        res += ans;
                }
                else if(str[i] == 'y')
                {
                    if(str[i-4] == 'h' && str[i-3] == 'e' && str[i-2] == 'a' && str[i-1] == 'v')
                        ans++;
                }
        }

        out(res);
    }
    return 0;
}