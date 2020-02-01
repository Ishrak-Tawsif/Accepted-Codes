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
#define mx                      1000005
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

ll fact[20],res,ncr[19][19];
string str;
int vis[19],taken[19],cnt[19];
map <vector<int>,int> mark;
vector <int> vv;

void genfact()
{
    fact[0] = 1;
    for(ll i=1; i<=20; i++) fact[i] = fact[i-1] * i;
}

void genncr()
{
    ncr[0][0] = 1;
    for(int i=1; i<=18; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j == 0) ncr[i][j] = 1;
            else if(j == 1) ncr[i][j] = i;
            else ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]);
        }
    }
}

ll calc(string cur)
{//out(cur);
    int curcnt[10];
    mem(curcnt,0);
    for(int i=0; i<cur.length(); i++) curcnt[cur[i] - '0']++;
    for(int i=0; i<10; i++) vv.pb(curcnt[i]);
    if(mark[vv]) return 0;

    ll ans = fact[cur.length()];
    
    for(int i=0; i<10; i++) ans /= fact[curcnt[i]];

    ///eliminating leading zeros

    if(!curcnt[0]) return ans;
    curcnt[0] --;
    ll now = fact[cur.length()-1];
    for(int i=0; i<10; i++) now /= fact[curcnt[i]];

    ans = ans - now;

    return ans;
}

void backtrack(int i,int ind,string cur)
{
    if(i == str.length())
    {
        vv.clear();
        ll now = calc(cur);
        res += now;
        mark[vv] = 1;
        return;
    }

    string temp = cur;
    
        int now = str[i] - '0';

        if(!now && !ind) return;

        if(!vis[i])
        {
            vis[i] = 1;
            if(taken[now] == 0)
            {
                taken[now]++;
                backtrack(i+1,ind+1,temp + str[i]);
            }
            else
            {
                backtrack(i+1,ind,temp);
                if(taken[now]<cnt[now])
                {
                    taken[now]++;
                    backtrack(i+1,ind+1,temp + str[i]);
                }
            }
            taken[now] --;
            vis[i] = 0;
        }
}

int main()
{
    
////    READ("in.txt");
////    WRITE("out.txt");

    genfact();
    genncr();
    
    cin>> str;

    for(int i=0; i<str.length(); i++) cnt[str[i] - '0'] ++;
    
    res = 0;
    backtrack(0,0,"");

    out(res);

    return 0;
}