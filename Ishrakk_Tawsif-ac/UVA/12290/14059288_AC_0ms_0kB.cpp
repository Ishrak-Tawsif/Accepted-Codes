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

int check(int num)
{
    int fl = 0;
    if(num % 7 == 0) return 1;
    while(num != 0)
    {
        int now = num%10;
        if(now == 7) return 1;
        num /= 10;
    }
    return 0;
}
vector <int> vv[103];

int main()
{
    int n,m,k;
//out(check(95635));
    while(scanf("%d %d %d", &n,&m,&k) == 3)
    {
        if(!n && !m && !k) break;

        ll cur = 0, now = 1,turn = 1;
        //n = 100;
        while(cur<=100000)
        {
            cur ++;
            if(check(cur))
            {
                vv[turn].pb(cur);
            }
            if(turn == n) now = -1;
            else if(turn == 1 && now == -1) now = 1;
            turn += now;
        }
        out(vv[m][k-1]);
        for(int i=0; i<=100; i++) vv[i].clear();
//        for(int i=1; i<=100; i++)
//        {
//            if(vv[i].size()<100)
//            {
//                //for(int j=0; j<vv[i].size(); j++) cout<<vv[i][j]<<endl;
//                system("pause");
//            }
//        }
    }

    return 0;
}