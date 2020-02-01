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
#define mx                      5000005
#define mod                     100000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/


ll e,p,k,r,res;

bool check(ll val)
{
    ll round = val/k;
    ll rest = val%k;
    ll tempe = e;

    if(round)tempe += (-(round*p*k));
    if(round)tempe += ((round-1)*r);

    if(tempe<=0) return 1;
    else
    {
        if(rest>0)
        {
            if(round)tempe += r;
            tempe -= (p*rest);
        }
        if(tempe<=0) return 1;
    }

    return 0;
}

int main()
{//WRITE("in.txt");
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%lld %lld %lld %lld", &e,&p,&k,&r);

        res = -1;
        
        casepf(tt);

            if(e<=(p*k))
            {
                pf("%lld\n",((e-1)/p)+1);
                continue;
            }

            ll s = 1,e = 1e10,mid;

            while(s<=e)
            {
                mid = (s+e)>>1;
                if(check(mid)) res=mid,e = mid-1;
                else s = mid+1;
            }

            pf("%lld\n", res);
        //}
    }
    return 0;
}