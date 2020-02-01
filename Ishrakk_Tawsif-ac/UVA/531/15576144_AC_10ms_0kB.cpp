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

string str,temp;
string a[103],b[103];
int inda,indb,dp[103][103],here,fl;

int call(int i,int j)
{
    if(i >= inda || j >= indb) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans;

    if(a[i] == b[j]) ans = call(i+1,j+1) + 1;
    else ans = max(call(i+1,j),call(i,j+1));

    return dp[i][j] = ans;
}

void print_it(int i,int j)
{//cout<<i<<" "<<j<<" "<<inda<<" "<<indb<<endl;
    if(i <=0 || j <=0) return;
    if(a[i] == b[j])
    {
        print_it(i-1,j-1);
        if(!fl) fl = 1,cout<<a[i];
        else cout<<" "<<a[i];
    }
    else if(dp[i-1][j]>dp[i][j-1])
    {
        print_it(i-1,j);
    }
    else print_it(i,j-1);
}

int main()
{
//    READ("in.txt");
//    WRITE("out.txt");
    while(1)
    {
        inda = 1;
        while(cin>> temp)
        {
            if(temp[0] != '#' || temp.length() != 1)a[inda++] = temp;
            else break;
        }

        indb = 1;
        while(cin>> temp)
        {
            if(temp[0] != '#' || temp.length() != 1)b[indb++] = temp;
            else break;
        }

//        for(int i=1; i<=inda; i++) cout<<i<<" "<<a[i]<<endl;
//        for(int i=1; i<=indb; i++) cout<<i<<" "<<b[i]<<endl;

        if(inda == 1 && indb == 1) break;

        mem(dp,0);//call(12,14);cout<<dp[12][14]<<endl;
//        for(int i=0; i<inda; i++)
//            for(int j=0; j<indb; j++)
//                {
//                    if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j] + 1;
//                    else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
//                }

        for(int i=1; i<inda; i++)
        {
            for(int j=1; j<indb; j++)
            {
                if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        fl = 0;
        print_it(inda-1,indb-1);
        pf("\n");
    }

    return 0;
}