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
#define mx                      1123
#define mod                     1000000009
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

int ar[105][105],n,m,k,sum[105][105];

ll dosum()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            sum[i][j] += sum[i-1][j];
            sum[i][j] += sum[i][j-1];
            sum[i][j] -= sum[i-1][j-1];
        }
    }
}

int call()
{
    int ans;
    ans = 0;
    //ans.second = 0;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                for(int tempi = i; tempi<=n; tempi++)
                {
                    for(int tempj=m; tempj>=j; tempj--)
                    {
                        int cost = sum[tempi][tempj];
                        cost -= sum[i-1][tempj];
                        cost -= sum[tempi][j-1];
                        cost += sum[i-1][j-1];

                        int curarea = (abs(i-tempi)+1) * (abs(j-tempj)+1);
//cout<<curarea<<endl;
                        if(cost<=k)
                        {
                            if(curarea>ans)
                            {
                                ans = curarea;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ans;
}

int main()
{//WRITE("in.txt");

    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        mem(sum,0);
        scanf("%d %d %d", &n,&m,&k);
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", &sum[i][j]);

        dosum();
        int res = call();

        pf("%d\n",res);
    }

    return 0;

}