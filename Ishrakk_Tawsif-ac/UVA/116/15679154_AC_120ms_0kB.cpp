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

int n,m;
ll dp[11][101],ar[11][101];
int vv[11][101];
vector <int> tempvec,resvec;

ll call(int i,int j)
{
    if(i == n && j == m) {vv[i][j] = i;return ar[i][j];}
    if(j>m) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    ll res ,res1,res2;

    int rr[5],c = j+1,tempr,minires;

    if(i-1 == 0) rr[0] = n;
    else rr[0] = i-1;

    if(i+1>n) rr[1] = 1;
    else rr[1] = i + 1;

    rr[2] = i;

    sort(rr,rr+3);
//cout<<i<<" "<<rr[0]<<" "<<rr[1]<<" "<<rr[2];
    tempr = rr[0];
    res = (call(rr[0],c) + ar[i][j]);
    minires = res;


    res1 =call(rr[1],c) + ar[i][j];
    if(minires>res1) minires = res1,tempr = rr[1];

    res2 = call(rr[2],c) + ar[i][j];

    if(minires>res2) minires = res2,tempr = rr[2];

    vv[i][j] = tempr;
//if(i == 1 && j == 1)cout<<i<<" "<<c<<" "<<rr[0]<<" "<<rr[1]<<" "<<rr[2]<<" "<<res<<" "<<res1<<" "<<res2<<endl;
    return dp[i][j] = minires;
}

int main()
{//READ("in.txt"); WRITE("out.txt");
    while(~scanf("%d %d", &n,&m))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++) sfll(ar[i][j]);
        }

        mem(dp,-1);

        ll finres = 2e14,res;
        for(int i=1; i<=n; i++)
        {
            mem(dp,-1);
            res = call(i,1);//out(res);
            if(res<=finres)
            {
                tempvec.clear();
                int r=i,c=1;
                while(c <= m)
                {
                    tempvec.pb(r);//cout<<" "<<r;
                    r = vv[r][c];
                    c++;
                }//cout<<endl;

                if(res<finres) resvec = tempvec,finres = res;
                else if(res == finres)
                {
                    int fl = 0;
                    for(int i=0; i<tempvec.size() && i<resvec.size(); i++)
                    {
                        if(tempvec[i]<resvec[i])
                        {
                            fl = 1;
                            break;
                        }
                        if(tempvec[i]>resvec[i]) break;
                    }
//cout<<i<<" ... "<<res<<" "<<finres<<" "<<fl<<endl;
                    if(fl) resvec = tempvec;
                    else
                    {
                        if(tempvec.size()<resvec.size()) resvec = tempvec;
                    }
                }
            }//cout<<res<<" "<<finres<<endl;
        }
//out(resvec.size());
        for(int i=0; i<resvec.size(); i++)
        {
            !i? pf("%d",resvec[i]) : pf(" %d", resvec[i]);
        }

        pf("\n%lld\n",finres);
    }

    return 0;
}