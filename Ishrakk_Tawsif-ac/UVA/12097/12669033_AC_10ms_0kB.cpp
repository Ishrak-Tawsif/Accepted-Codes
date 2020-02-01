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
#define casepf(nn)              printf ("Case %d: ",nn)
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
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

#define pi acos(-1.0)
#define till 1e-6
double ar[100005];

bool check(double val,int n,int f)
{
    int tot = 0;
    for(int i=0; i<n; i++)
    {
        tot += (int)(ar[i]/val);
    }
    return tot>=f;
}

int main()
{
    int n,f,tc;
    sf(tc);
    while(tc--)
    {
        sf(n);
        sf(f);

        double temp,st = 0.0,en = 0.0,sum=0.0;
        for(int i=0; i<n; i++)
        {
            cin>> temp;
            ar[i] = pi * temp * temp;
            en = max(en,ar[i]);
        }

        double mid,res=0.0;
        while(en - st>till)
        {
            mid = (st+en)/2.0;
            if(check(mid,n,f+1)) res = mid,st = mid/*,out("ok")*/;
            else en = mid;
        }

        pf("%.7f\n", mid);
    }
    return 0;
}