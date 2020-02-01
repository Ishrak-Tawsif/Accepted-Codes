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
#define Unique_(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define mx                      262144+7
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int main()
{
    fast;

    ll s,e;

    while(cin>> s>> e)
    {
//        ll cnt = 0;
//        for(ll i=s; i<=e; i++)
//        {
//            string str = tostring(i);
//            if(str[0] == str[str.length()-1]) cnt++;
//        }
//        out(cnt);
        ll cnt = 0;
        while(s%10 != 0)
        {
            if(s>e) break;
            string str = tostring(s);
            if(str[0] == str[str.length()-1]) cnt++;//cout<<s<<" "<<cnt<<endl;
            s++;
        }
        while(e%10 != 0)
        {
            if(e<=s) break;
            string str = tostring(e);
            if(str[0] == str[str.length()-1]) cnt++;
            e--;
        }//cout<<s<<" "<<e<<" "<< cnt<<endl;
        if(s<e)
        {
            ll now = e-s;
            cnt = cnt + (now/10);
        }
        out(cnt);
    }

    return 0;
}