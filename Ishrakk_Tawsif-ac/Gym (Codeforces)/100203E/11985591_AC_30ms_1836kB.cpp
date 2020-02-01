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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

vector <int> vv;

int main()
{
    int n;

    sf(n);
    string s1,s2;
    for(int i=0; i<n; i++)
    {
        cin>> s1>> s2;

        int ans = 0,one = 0,zero = 0,cnt=0;
        for(int i=0; i<s1.length(); i++)
        {
            if(s1[i] == '?') {ans++;if(s2[i] == '1') cnt++;}
            else if(s1[i] != s2[i])
            {
                if(s1[i] == '1') one++;
                else zero ++;
            }
        }
//cout<<zero<< " " << one << endl;

        casepf(i+1);
        if(one>zero)
        {
            if(one-zero>cnt)cout<<"-1\n";
            else cout<< ans+one <<endl;
            continue;
        }

        int temp = min(one,zero);
        ans += temp;
        one -= temp;
        zero -= temp;

        ///amar cnt sonkhok 1 ke ? er jaygay bosano somvob,kintu amar one sonkhok place ache jekhane 0 bosano dorkar amar ache one
        ///so ekhane ami ? er jaygay 1 na bosiye min(one,cnt) sonkhok 0 bosabo ar onno 1 er sathe swap krbo jar mot cost 2(min(one,cnt)
        temp = min(one,cnt);
        ans += 2*temp;
        one -= temp;
        cnt-= temp;

        if(zero>0) ans += zero,zero=0;

        if(one>0 || zero>0) cout<<"-1\n";
        else cout<<ans<<endl;
    }
    return 0;
}