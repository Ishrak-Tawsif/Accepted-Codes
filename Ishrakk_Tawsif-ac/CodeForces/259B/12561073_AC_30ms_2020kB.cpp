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
#define mx                      100000
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int ar[5][5],cnt[5];

int main()
{
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) sf(ar[i][j]);

    int f,s,t;
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) cnt[i] += ar[i][j];
    for(int i=1; i<=mx; i++)
    {
        int temp = cnt[0] + i;
        //fl = 1;

        if(temp>cnt[1] && temp>cnt[2])
        {
            f = i;
            s = temp-cnt[1];
            t = temp-cnt[2];
            int fl = 1;

            if(f + s + t != temp) fl = 0;
            if(ar[0][2] + s + ar[2][0] != temp) fl = 0;
            if(f + ar[1][0] + ar[2][0] != temp) fl = 0;
            if(s + ar[0][1] + ar[2][1] != temp) fl = 0;
            if(t + ar[0][2] + ar[1][2] != temp) fl = 0;


            if(fl)break;
        }
    }
//cout<<f<<" "<<s<<" "<<t<<endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i == 0 && j == 0) pf("%d",f);
            else if(i == 1 && j == 1) pf("% d",s);
            else if(i == 2 && j == 2) pf("% d",t);
            else
            {
                if(j == 0)pf("%d", ar[i][j]);
                else pf(" %d", ar[i][j]);
            }
        }
        pf("\n");
    }

    return 0;
}