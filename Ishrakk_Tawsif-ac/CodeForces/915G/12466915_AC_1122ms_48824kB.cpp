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
#define mx                      2000000 + 5
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

ll divv[mx],powval[mx],ans[mx];

void gendiv()
{
    for(int i=2; i<mx; i++)
    {
        for(int j=i+i; j<mx; j+=i) divv[j] ++;
    }
}

int main()
{
    ll n,k;

    gendiv();
    cin>> n>> k;

    ll temp,tot = 0,tempres,last=-1;
    powval[0] = 1;
    powval[1] = 1;
    ans[1] = 1;
    for(ll i=1; i<=k; i++)
    {
        powval[i] = BigMod(i,n);
        temp = (powval[i] - powval[i-1]);
        temp += mod;
        temp %= mod;
        temp -= -1;
        temp += mod;
        temp %= mod;
        //cout<<i<<" "<<ans[i]<<" "<<temp<<endl;
        ans[i] += temp;

        ans[i] %= mod;

        ans[i] -= 1;
        ans[i] += mod;
        ans[i] %= mod;

        for(ll j=2; i*j<=k; j++) ans[i*j] -= ans[i];

    }

    ll sum = 0,res;
    for(ll i=1; i<=k; i++)
    {
        //cout<<i<<" "<<ans[i]<<endl;
        if(i == 1)
        {
            sum = ans[i];
            res = (sum^1);
        }
        else sum += ans[i],sum%=mod,res += (sum^i),res%=mod;//out(sum);
    }
    out(res%mod);
    return 0;
}