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

int n,t,m,ar[1005],ind,dp[1005][1005][105];

int convert(string s)
{
    string temp = "";
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='0' && s[i]<='9') temp += s[i];
    }
    int now = (int)toint(temp);
    return now;
}

int call(int ind,int disk,int mem)
{
    if(ind>n || disk>m) return 0;
    if(dp[ind][disk][mem] != -1) return dp[ind][disk][mem];

    int ans = -2e9;

    if(mem+ar[ind] <= t) ans = max(call(ind+1,disk,mem+ar[ind])+1,call(ind+1,disk,mem));
    else ans = max(call(ind+1,disk,mem),call(ind,disk+1,0));
    //ans = max(ans,call(ind,disk+1,0));

    return dp[ind][disk][mem] = ans;
}

int main()
{//READ("in.txt");WRITE("out.txt");
    string str,temp;
    int tc;

    sf(tc);
//out(tc);
    for(int tt=1; tt<=tc; tt++)
    {

        scanf("%d %d %d", &n,&t,&m);//cout<<n<<" ... "<<t<<" "<<m<<endl;

        getchar();
        getline(cin,str);//out(str);
        stringstream ss(str);

        ind = 0;
        while(ss>> temp)
        {
            //out(temp);
            int now = convert(temp);
            ar[++ind] = now;
        }
        //for(int i=1; i<=ind; i++) out(ar[i]);
        mem(dp,-1);
        int ans = call(1,1,0);//out(tt);
        pf("%d\n", ans);
        if(tt != tc) pf("\n");
    }

    return 0;

}