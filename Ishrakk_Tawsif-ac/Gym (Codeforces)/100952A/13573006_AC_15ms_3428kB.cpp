///>>>>>>>>>>>>>>>>>>>>

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
#define casepf(nn)              printf ("Case #%d: ",nn)
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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      2000005
#define mod                     1000000007
#define flush                   fflush(stdout)

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

double h1,m1,s1;
double h2,m2,s2;

void func()
{
    if(h1 == h2)
        {
            if(m1 == m2)
            {
                if(s1 == s2)
                {
                    cout<<"Tie\n";
                }
                else
                {
                    if(s1<s2) cout<<"Player1\n";
                    else cout<<"Player2\n";
                }
            }

            else
            {
                if(m1<m2) cout<<"Player1\n";
                else cout<<"Player2\n";
            }

        }

        else
        {
            if(h1<h2) cout<<"Player1\n";
            else cout<<"Player2\n";
        }
}

int main()
{
    int tc;
    sf(tc);

    while(tc--)
    {
        cin>> h1>> m1>> s1>> h2>> m2>> s2;

        func();
    }

    return 0;
}