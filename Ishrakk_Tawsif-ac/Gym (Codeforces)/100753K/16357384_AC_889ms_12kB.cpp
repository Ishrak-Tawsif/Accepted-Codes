#include <bits/stdc++.h>
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
#define loop1(var,start,till)   for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

ll convert(ll n)
{
    if(n == 0) return 0LL;
    if(n == 1) return 1LL;
    if(n == 2) return 2LL;
    if(n == 5) return 5LL;
    if(n == 8) return 8LL;
    if(n == 6) return 9LL;
    if(n == 9) return 6LL;
    return -1LL;
}

int main()
{
    ll n,fl = 1;

    sfll(n);

    ll tll = sqrt(n);

    for(ll i=2; i<=tll+(ll)2; i++)
    {
        if(n%i == 0)
        {
            fl = 0;
            break;
        }
    }

    if(n == 2)
    {
        printf("yes\n");
        return 0;
    }

    if(n == 1) fl = 0;

    if(!fl)
    {
        printf("no\n");
        return 0;
    }

    ll temp = n,now = 0;

    while(temp != 0)
    {
        ll cur = temp % 10LL;
        temp /= 10LL;
        cur = convert(cur);
        if(cur == -1)
        {
            fl = 0;
            break;
        }
        now = (now * 10LL) + cur;
    }
    if(!fl) printf("no\n");
    else
    {
        ll till = sqrt(now);
        for(ll i=2; i<=till+2; i++)
        {
            if(now%i == 0)
            {
                fl = 0;
                break;
            }
        }
        if(!fl || now == 1LL) printf("no\n");
        else printf("yes\n");
    }
    return 0;
    ///////
}