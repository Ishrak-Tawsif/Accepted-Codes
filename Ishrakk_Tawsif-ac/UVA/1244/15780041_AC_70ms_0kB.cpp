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

int n;
string temp[51];
vector <vector<string> >dp;

string call(int i,int j)
{//cout<<i<<" "<<j<<endl;
    if(i == j)
    {
        return "";
    }
    if(i>j) return "*";
    if(dp[i][j] != "-") return dp[i][j];
//cout<<i<<" ||| "<<j<<endl;
    string res = ""; res += temp[i][j];

    for(int k=i+1; k<n; k++)
    {
        for(int l=j-1; l>=0; l--)
        {
            if(temp[i][k] == temp[j][l])
            {
                string now = call(k,l);//out(now);
                if(now == "*") continue;
                now = temp[i][k] + now + temp[j][l];//out(now);
                if(res.length()<now.length()) res = now;
                else if(res.length() == now.length())
                {
                    res = min(res,now);
                }
            }
        }
    }
    return dp[i][j] = res;
}

int main()
{//READ("in.txt");WRITE("out.txt");
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(n);
        for(int i=0; i<n; i++) cin>> temp[i];

        dp.assign(60,vector<string>());
        for(int i=0; i<60; i++) for(int j=0; j<60; j++) dp[i].pb("-");//out("fe");

        string res = call(0,n-1);//out(res);
        cout<<res<<endl;
    }
    return 0;
}