#include <bits/stdc++.h>
#include <ext/rope>

using namespace __gnu_cxx;
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
#define mx                      100005
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

//int n,m,r;
//ll ar[503],res,dp[503][53][53];
//
//ll call(int ind,int curm,int curr)
//{
//    if(curm == m) return 0;
//
//    if(ind>=n+1)
//    {
//        if(curm == m) return 0;
//        else return -2e9;
//    }
//
//    if(dp[ind][curm][curr] != -1) return dp[ind][curm][curr];
//
//    ll ans = 0,ans1=0,ans2=0;
//
//    if(curr == r) ans = call(ind+1,curm,1);
//    else
//    {
//        ans1 += call(ind+1,curm,1);
//        ans2 += max(ans,(call(ind+1,curm+1,curr+1) + (ar[ind] * (ll)curr)));
//        ans = max(ans1,max(ans2,call(ind+1,0,1)));
//    }
//    out(ans);
//    return dp[ind][curm][curr] = ans;
//}
//
//int main()
//{
//    scanf("%d %d %d", &n,&m,&r);
//    for(int i=1; i<=n; i++) sfll(ar[i]);
//
//    res = -2e9;
//
//    mem(dp,-1);
//    call(1,0,1);
//
//    if(res != -2e9)out(res);
//    else pf("-1\n");
//
//    return 0;
//
//}
//
///*
//10 3 3
//10 10 9 6 5 4 2 1 4 4
//
//*/

int main()
{
    string str,res;

    getline(cin,str);

    int cnt = 0,fl = 1;

    stringstream ss(str);
    string temp;

    while(ss>> temp) cnt++;
//out(cnt);
    if(cnt>1) fl = 0;
    else
    {
        temp = str;
        if(str[0] == ' ')
        {
            str = "";
            for(int i=0; i<temp.length(); i++)
            {
                if(temp[i] != ' ') str += temp[i];
            }
        }//out(temp);

        if(str.length() == 0)
        {
            out("invalid input");
            return 0;
        }

        for(int i=0; i<str.length(); i++)
        {
            if(str[i]>='0' && str[i]<='9');
            else fl = 0;
        }
        if(fl)
        {//out("ok");
            int nici = 0;
            res = "";
            for(int i=0; i<str.length(); i++)
            {
                if(str[i] == '0' && !nici) continue;
                else res += str[i],nici = 1;
            }
        }
    }
    if(res.length() == 0 && fl)
    {
        out("0");
        return 0;
    }
    fl? out(res) : out("invalid input");

    return 0;
}