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
#define mx                      10005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/


int main()
{
    int res = 0,n;
    string str;

    sf(n);
    cin>> str;

    int fl = -1,last = -1,tot=0;
    for(int i=0; i<str.length(); i++)
    {
        //if(str[i] != '.' && fl == -1) fl = i;
        //if(str[i] != '.') last = i;
        if(str[i] == 'R')
        {
            if(fl == -1)last = i,fl=i;
            else last = i;
            tot ++;
        }
        else if(str[i] == 'L')
        {
            if(fl == -1)last = i,fl=i;
            else last = i;
            if(tot)
            {
                tot --;
                if(tot%2) res ++;
                tot = 0;
            }
        }
        else
        {
            if(fl == -1) continue;
            else
            {
                if(str[last] != 'R') res++;
                else tot++;
            }
        }
    }
//out(res);
    if(str[fl] == 'R') res+=fl;
    if(last == -1) res = n;

    pf("%d\n", res);

    return 0;
}