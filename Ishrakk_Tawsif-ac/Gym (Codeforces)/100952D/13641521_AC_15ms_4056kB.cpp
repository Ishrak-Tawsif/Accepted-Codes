///>>>>>>>>>>>>>>>>>>>>

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
#define casepf(nn)              printf ("Case #%d: ",nn)
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
#define flush                   fflush(stdout)

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,m,k,d;
//ll ar[205],dp[205][205][53];
//
//ll call(int pos,int bst,int frd)
//{cout<<pos<<" "<<bst<<" "<<frd<<endl;
//    if(pos > n) {if(bst == 0 && frd == 0) return 1; else return 0;}
//    if(dp[pos][bst][frd] != -1) return dp[pos][bst][frd]%mod;
//
//    ll ans=0;
//cout<<pos<<" ................ \n";
//    if(ar[pos]>=d)
//    {
//        if(bst)ans += (call(pos+1,bst-1,frd)%mod);
//        if(frd)ans += (call(pos+1,bst,frd-1)%mod);
//        if(!bst && !frd) ans += call(pos+1,bst,frd);
//    }
//    else
//    {
//        if(frd) ans += (call(pos+1,bst,frd-1)%mod);
//        if(!bst && !frd) ans += call(pos+1,bst,frd);
//    }
//    return dp[pos][bst][frd] = ans%mod;
//}

ll ncr[205][205];

void pregen()
{
    ncr[0][0] = 1;
    for(int i=1; i<205; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(!j) ncr[i][j] = 1;
            else if(j == 1) ncr[i][j] = i;
            else ncr[i][j] = (ncr[i-1][j]%mod + ncr[i-1][j-1]%mod)%mod;
        }
    }
}

vector <ll> vv;

int main()
{//READ("in.txt");
    int tc;
    ll temp;
    pregen();
    sf(tc);

    while(tc--)
    {
        //mem(dp,-1);
        scanf("%d %d %d %d", &n,&m,&k,&d);

        for(int i=1; i<=n; i++) sfll(temp),vv.pb(temp);//out(tc);

        sort all(vv);

        if(!m && !k) {pf("1\n"); vv.clear();continue;}

        ll ans = 0;
        
        for(int i=0; i<vv.size(); i++)
        {
            ll now = vv[i];
            if(now>=d) ans += (ncr[n-(i+1)][k-1] * ncr[i][m-k])%mod;
            ans%=mod;
        }

        if(!k)
        {
            ans = 0;
            for(int i=0; i<vv.size(); i++)
            {
                ans += ncr[i][m-1]%mod;//out(i+1);
                ans%=mod;
            }
        }

        pf("%lld\n", ans%mod);
        vv.clear();
    }
    
    return 0;
}