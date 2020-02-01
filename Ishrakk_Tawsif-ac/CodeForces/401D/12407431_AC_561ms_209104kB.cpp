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
#define mx                      11
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

ll lim,n,m;
ll dp[(1<<18)+1][101],ar[19];
string str;

ll call(int mask,int tot)
{//cout<<mask<<" "<<lim<<" "<<pos<<endl;
    if(mask == lim) {if(!tot) return 1; return 0;}

    if(dp[mask][tot] != -1) return dp[mask][tot];

    ll ans = 0,tempmask=0;

    for(int i=0; i<str.length(); i++)
    {
        if(mask == 0 && ar[i] == 0) continue;
        if(!(mask & (1<<i)) && !(tempmask & (1<<ar[i])))
        {//out(ar[i]);
            tempmask |= (1<<ar[i]);
            ans += call(mask | (1<<i),(((tot%m)*10)+ar[i])%m);
        }
    }
    return dp[mask][tot] = ans;
}

int main()
{//WRITE("out.txt");
    //int n;

    //facto();
    //int tc;//out(fact[10]);
    //sf(tc);

    //for(int tt=1; tt<=tc; tt++)
    //{
        cin>> str;
        sf(m);

        //mem(cnt,0);
        for(int i=0; i<str.length(); i++) ar[i] = (ll) (str[i] - '0');

        lim = (1<<str.length())-1;
        mem(dp,-1);
        ll res = call(0,0);

        /*casepf(tt);*/ pf("%lld\n", res);
    //}

    return 0;
}