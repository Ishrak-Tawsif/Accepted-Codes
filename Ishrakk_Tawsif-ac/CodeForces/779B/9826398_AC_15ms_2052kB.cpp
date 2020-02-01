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
#define mx                      1000005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int vis[11][11];

int main()
{
    string str;
    int k;

        cin>> str;
        sf(k);

            int len = str.length(),zero=0,ans=0;

                for(int i=len-1; i>=0; i--)
                {
                    if(str[i] == '0') zero++;
                    else ans++;

                    if(zero == k) break;
                }
                if(zero != k) ans = len-1;

                pf("%d\n", ans);
    return 0;
}